package com.os;

import java.util.*;

public class SRTF extends Scheduler{
    private PriorityQueue<SRTFProcess> processingQueue;
    public SRTF(List<Process> processes){
        super(processes);
        processingQueue = new PriorityQueue<>();
    }

    public void run(){
        SRTFProcess currentProcess = null;

        while( !processingQueue.isEmpty() || !arrivalQueue.isEmpty() || currentProcess != null){
            updateTime();
            updateQueue();

            //process the first process from queue
            if(currentProcess != null) {
                System.out.print("Time: " + (clock-1) + " -> " +currentProcess);
                currentProcess.decBurstTime();
                if (!currentProcess.finished()) {
                    currentProcess.setStatus(STATUS.READY);
                    processingQueue.add(currentProcess);
                } else {
                    processedList.add(currentProcess);
                    currentProcess = null;
                }
            }
            if(!processingQueue.isEmpty()) {
                currentProcess = processingQueue.poll();
            }
            clock++;
        }
        printStats();
    }
    private void updateTime(){
        //increase turnaround and waiting time
        for(Process process : processingQueue){
            if(process.getStatus() == STATUS.READY){
                process.incWaitingTime();
                process.incTurnAroundTime();
            }else if (process.getStatus() == STATUS.WAITING){
                process.incWaitingTime();
            }
        }
    }

    private void updateQueue(){
        //get all processes whom arrived at time "clock"
        for(int i = 0; i < arrivalQueue.size(); i++) {
            if (clock == arrivalQueue.get(i).getArrivalTime()){
                processingQueue.add((SRTFProcess) arrivalQueue.get(i));
                arrivalQueue.remove(i);
                i--;
            }else{
                break;
            }
        }
    }
}

class SRTFProcess extends Process implements Comparable<SRTFProcess>{
    public SRTFProcess(){}

    public SRTFProcess(String name, int arrivalT, int burstT) {
        super(name, arrivalT, burstT);
    }

    @Override
    public int compareTo(SRTFProcess srtfProcess) {
        return this.getBurstTime() - srtfProcess.getBurstTime() ;
    }
}