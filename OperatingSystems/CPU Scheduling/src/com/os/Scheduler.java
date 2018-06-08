package com.os;

import java.util.LinkedList;
import java.util.List;

public abstract class Scheduler {
    protected LinkedList<Process> processedList;
    protected LinkedList<Process> arrivalQueue;
    protected int clock;

    Scheduler(List<Process> processes){
        clock = 0;
        processes.sort(new SRTFProcess());
        arrivalQueue = new LinkedList<>();
        arrivalQueue.addAll(processes);
        processedList  = new LinkedList<>();
    }

    protected void printStats() {
        int avgWT = 0;
        int avgTAT = 0;
        for(Process process : processedList){
            String pName = process.getProcessName();
            int wt  = process.getWaitingTime();
            int tat = process.getTurnAroundTime();
            System.out.printf( "Process: %s { Waiting: %s , Turnaround: %s }\n", pName, wt, tat );
            avgWT += wt;
            avgTAT += tat;
        }
        System.out.printf("The Average Wait Time is: %s\n", avgWT/processedList.size());
        System.out.printf("The Average Turnaround Time is: %s\n", avgTAT/processedList.size());
    }
}
