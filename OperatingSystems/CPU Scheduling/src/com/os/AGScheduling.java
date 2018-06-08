package com.os;

import javax.swing.plaf.FontUIResource;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

/** Each process is provided a static time to execute called quantum.
 * Once a process is executed for given time period, it’s called non-preemptive till the finishing of (ceil(50%)) of its Quantum time
 * , after that it’s converted to preemptive Shortest- Job  First (SJF).
 *
 * We have 3 scenarios of the running process
 i. The running process used all its quantum time and it still have job to do (add this process to the end of the queue,
 then increases its Quantum time by one).


 The running process didn’t use all its quantum time based on another process converted from ready to running (add this process to the end of the queue,
 and then increase its Quantum time by the remaining Quantum time).

 The running process didn’t use all its quantum time because it’s
 no longer need that time and the job was completed (set it’s quantum time to zero).

 **/
public class AGScheduling extends Scheduler {


    private LinkedList<AGProcess> processingQueue;
    private int clock;

    AGScheduling(List<Process> processes){
        super(processes);
        processes.sort(new AGProcess());
        processingQueue = new LinkedList<>();
    }



    public void run(){

        AGProcess currentProcess;
        while( !processingQueue.isEmpty() || !arrivalQueue.isEmpty()){
            //System.out.println(processingQueue);
            boolean done = false;
            //add elements whom came at time "clock" to the processing queue
            updateQueue();

            //if empty, increase time and repeat
            if(processingQueue.isEmpty()){
                clock++;
                continue;
            }

            //there are processes in the queue;
            //get the first, set it to 'NON_PREEMPTIVE'
            //and do the first step in processing, decrease the ceil(q) and update your time
            currentProcess = processingQueue.poll();
            currentProcess.setStatus(STATUS.READY);
            currentProcess.setScheme(com.os.SCHEME.NON_PREEMPTIVE);
            int ceilQTime = currentProcess.getCeilQTime();
            int burstTime = currentProcess.getBurstTime();
            int timeToPass = burstTime < ceilQTime ? burstTime:ceilQTime;
            clock += timeToPass;
            burstTime -= timeToPass;
            currentProcess.decBurstTime(timeToPass);
            updateQueue();
            updateTime(timeToPass);
            //update time for processes in processingQueue

            System.out.println("Time {"+(clock-timeToPass)+":"+clock+"} Process: "+currentProcess);

            //if finished, go for the next process
            //that means the timeToPass mostly was burstTime
            if(currentProcess.finished()){
                //put in processed list and continue
                //{{{{{{{  CASE 3: in Assignment  }}}}}}}
                processedList.add(currentProcess);
                System.out.println("Process: "+currentProcess.getProcessName()+" Finished." );
                continue;
            }

            //not finished yet
            int remainingQTime = currentProcess.getQuantumTime() - ceilQTime;

            //now the process became preemptive
            currentProcess.setScheme(com.os.SCHEME.PREEMPTIVE);
            //check every time step until there is a new process with
            //burst time < the remaining burst time, or the process has finished
            while(!currentProcess.finished() && remainingQTime != 0){
                updateQueue();
                int m_p_in_q = minProcessInQueue(burstTime);
                //if no process has burstTime less than the currentProcess
                if( m_p_in_q == -1 ){
                    clock++;
                    updateTime(1);
                    remainingQTime--;
                    burstTime--;
                    currentProcess.decBurstTime();
                    System.out.println("Time: {"+clock+"} Process: "+currentProcess);
                }else{
                    System.out.println("Process: "+currentProcess.getProcessName()+" Interrupted." );
                    //there is a process with burst time less than currentProcess
                    //{{{{{{{  CASE 2: in Assignment  }}}}}}}
                    putSmallestFirst(currentProcess, remainingQTime, m_p_in_q);
                    done = true;
                    break;
                }
            }
            // if notFinished or notEndedBurstTime --> used a new process mn l a5er
            if(done){
                continue;
            }
            if(currentProcess.finished()){
                //{{{{{{{  CASE 3: in Assignment  }}}}}}}
                processedList.add(currentProcess);
                System.out.println("Process: "+currentProcess.getProcessName()+" Finished." );
                putSmallestFirst(null, 0,  minProcessInQueue(-1) );
            }else if( remainingQTime == 0 ){
                //{{{{{{{  CASE 1: in Assignment  }}}}}}}
                currentProcess.incQuantumTime();
                processingQueue.add(currentProcess);
                System.out.println("Process: "+currentProcess.getProcessName()+" Finished QTime." );
            }
        }
        printStats();
    }

    private void putSmallestFirst(AGProcess currentProcess, int remainingQTime, int m_p_in_q){
        if(currentProcess != null) {
            currentProcess.incQuantumTime(remainingQTime);  //increase qTime by remaining qTime
            processingQueue.add(currentProcess);            //add currentProcess to queue
        }
        currentProcess = processingQueue.get(m_p_in_q); //get that new process
        processingQueue.remove(m_p_in_q);               //remove it from queue
        // add it infront of the queue, so we get it at the begining of the queue
        processingQueue.add(0, currentProcess);
    }

    private int minProcessInQueue(int bTime){
        bTime = bTime == -1 ? 10000:bTime;
        int index = -1;
        for(int i = 0; i < processingQueue.size(); i++){
            if(processingQueue.get(i).getBurstTime() < bTime){
                index = i;
            }
        }
        return index;
    }

    private void updateTime(int t){
        //increase turnaround and waiting time
        for(AGProcess process : processingQueue){
            if(process.getStatus() == STATUS.READY){
                process.incWaitingTime(t);
                process.incTurnAroundTime(t);
            }else if (process.getStatus() == STATUS.WAITING){
                process.incWaitingTime(t);
            }
        }
    }
    private void updateQueue(){
        //get all processes whom arrived at time "clock"
        for(int i = 0; i < arrivalQueue.size(); i++) {
            if (clock >= arrivalQueue.get(i).getArrivalTime()){
                processingQueue.add((AGProcess) arrivalQueue.get(i));
                arrivalQueue.remove(i);
                i--;
            }else{
                break;
            }
        }
    }

    enum SCHEME {PREEMPTIVE, NON_PREEMPTIVE, NONE}

}
class AGProcess extends Process implements Comparable<AGProcess> {
    private int quantumTime ;
    private SCHEME scheme;
    AGProcess() {
        super("" ,0 ,0 ) ;
        this.quantumTime = 0 ;
        scheme = SCHEME.NONE ;
    }

    public AGProcess(String name, int arrivalT, int burstT , int pQTime) {
        super(name, arrivalT, burstT);
        this.quantumTime = pQTime ;

    }

    @Override
    public int compareTo(AGProcess agProcess) {
        return this.getBurstTime() - agProcess.getBurstTime();
    }


    public int getQuantumTime(){ return quantumTime; }
    public int getCeilQTime(){ return (int)Math.ceil(quantumTime/2.0); }
    public void incQuantumTime(){incQuantumTime(1);}
    public void incQuantumTime(int quantumTime){this.quantumTime += quantumTime; }

    public SCHEME getScheme() {return scheme; }
    public void setScheme(SCHEME scheme) { this.scheme = scheme; }
    @Override
    public String toString(){
        return "Name: " + getProcessName() + ", ArrivalTime: " + getArrivalTime()
                + ", BurstTime: " + getBurstTime()+ ", quantum Time : " + quantumTime + "\n";
    }
}