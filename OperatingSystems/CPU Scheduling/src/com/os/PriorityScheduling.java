package com.os;

import java.util.List;
import java.util.PriorityQueue;

public class PriorityScheduling extends Scheduler {
    private PriorityQueue<PSProcess> processingQueue;

    public PriorityScheduling(List<Process> processes){
        super(processes);
        processingQueue = new PriorityQueue<>();
    }

    public void run() {
        while(!processingQueue.isEmpty() || !arrivalQueue.isEmpty()) {
            updateQueue();

            if (processingQueue.isEmpty()){
                clock++;
                continue;
            }

            PSProcess currentProcess = processingQueue.poll();
            currentProcess.setStatus(STATUS.READY);
            int pBTime = currentProcess.getBurstTime();

            clock += pBTime;
            currentProcess.decBurstTime(pBTime);

            updateTime(pBTime);
            updateQueue();

            /*if(currentProcess.finished()){
                processedList.add(currentProcess);
            }else {
                processingQueue.add(currentProcess);
            }*/
            processedList.add(currentProcess);
            System.out.println( "Process: " + currentProcess.getProcessName() + " -> time {from: " + (clock-pBTime)   + ", to: "+ clock + "}" );
        }
        printStats();
    }

    private void updateQueue(){
        //get all processes whom arrived at time "clock"
        for(int i = 0; i < arrivalQueue.size(); i++) {
            if (clock >= arrivalQueue.get(i).getArrivalTime()){
                processingQueue.add((PSProcess) arrivalQueue.get(i));
                arrivalQueue.remove(i);
                i--;
            }else{
                break;
            }
        }
    }

    private void updateTime(int t){
        //increase turnaround and waiting time
        for(PSProcess process : processingQueue){
            if(process.getStatus() == STATUS.READY){
                process.incWaitingTime(t);
                //process.incTurnAroundTime(t);
            }else if (process.getStatus() == STATUS.WAITING){
                process.incWaitingTime(t);
                //process.decPriority(2);
            }
        }
    }
}


class PSProcess extends Process implements Comparable<PSProcess>{
    private int priority;
    public PSProcess(String name, int arrivalT, int burstT, int priority){
        super(name, arrivalT, burstT);
        this.priority = priority;
    }

    @Override
    public int compareTo(PSProcess psProcess) {
        return this.getPriority() - psProcess.getPriority() ;
    }

    public int getPriority() {
        return priority;
    }
    public void decPriority(int p) {
        this.priority -= p;
    }
}