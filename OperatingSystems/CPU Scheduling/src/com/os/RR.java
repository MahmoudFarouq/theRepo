package com.os;

import java.util.LinkedList;
import java.util.List;

public class RR extends Scheduler{
    private LinkedList<RRProcess> processingQueue;
    private int qTime;

    public RR(List<Process> processes, int qTime){
        super(processes);
        this.qTime = qTime;
        processingQueue = new LinkedList<>();
    }

    public void run() {
        while(!processingQueue.isEmpty() || !arrivalQueue.isEmpty()) {
            updateQueue();

            if (processingQueue.isEmpty()){
                clock++;
                continue;
            }
            RRProcess currentProcess = processingQueue.poll();
            currentProcess.setStatus(STATUS.READY);
            int pBTime = currentProcess.getBurstTime();

            int timeToAdd = pBTime > qTime ? qTime:pBTime;
            clock += timeToAdd;
            currentProcess.decBurstTime(timeToAdd);

            updateTime(timeToAdd);
            updateQueue();

            if(currentProcess.finished()){
                processedList.add(currentProcess);
            }else {
                processingQueue.add(currentProcess);
            }
            System.out.println( "Process: " + currentProcess.getProcessName() + " -> time {from: " + (clock-timeToAdd)   + ", to: "+ clock + "}" );
        }
        printStats();
    }

    private void updateQueue(){
        //get all processes whom arrived at time "clock"
        for(int i = 0; i < arrivalQueue.size(); i++) {
            if (clock >= arrivalQueue.get(i).getArrivalTime()){
                processingQueue.add((RRProcess) arrivalQueue.get(i));
                arrivalQueue.remove(i);
                i--;
            }else{
                break;
            }
        }
    }

    private void updateTime(int t){
        //increase turnaround and waiting time
        for(RRProcess process : processingQueue){
            if(process.getStatus() == STATUS.READY){
                process.incWaitingTime(t);
                process.incTurnAroundTime(t);
            }else if (process.getStatus() == STATUS.WAITING){
                process.incWaitingTime(t);
            }
        }
    }

}

class RRProcess extends Process implements Comparable<RRProcess>{
    public RRProcess(String name, int arrivalT, int burstT) {
        super(name, arrivalT, burstT);
    }
    @Override
    public int compareTo(RRProcess rrProcess) {
        return 0;
    }
}