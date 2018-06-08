package com.os;

import java.util.Comparator;

enum STATUS { READY, WAITING }
enum SCHEME {PREEMPTIVE, NON_PREEMPTIVE, NONE}
public class Process implements Comparator<Process>{
    private int arrivalTime;
    private int burstTime;
    private int waitingTime;
    private int turnAroundTime;
    private String processName;
    private STATUS status;


    public Process(String name, int arrivalT, int burstT){
        setValues(name, arrivalT, burstT);
    }

    public Process(){
        setValues(null, 0, 0);
    }

    private void setValues(String name, int arrivalT, int burstT){
        this.processName = name;
        this.arrivalTime = arrivalT;
        this.burstTime = burstT;
        this.waitingTime = 0;
        this.turnAroundTime = 0;
        this.status = STATUS.WAITING;
    }

    public int getArrivalTime() {
        return arrivalTime;
    }

    public String getProcessName() {
        return processName;
    }

    public int getBurstTime() {
        return burstTime;
    }
    public int getWaitingTime() {
        return waitingTime;
    }
    public int getTurnAroundTime() {
        return turnAroundTime;
    }

    public void decBurstTime(){
        decBurstTime(1);
    }
    public void decBurstTime(int t){
        this.burstTime -= t;
    }

    public void incWaitingTime() {
        incWaitingTime(1);
    }
    public void incWaitingTime(int t){
        waitingTime += t;
    }

    public void incTurnAroundTime() {
        incTurnAroundTime(1);
    }
    public void incTurnAroundTime(int t) {
        turnAroundTime += t;
    }

    public boolean finished(){
        return burstTime <= 0;
    }

    public STATUS getStatus() {
        return status;
    }

    public void setStatus(STATUS status) {
        this.status = status;
    }

    @Override
    public String toString(){
        return "Name: " + getProcessName() + ", ArrivalTime: " + getArrivalTime()
                + ", BurstTime: " + getBurstTime() + "\n";
    }


    @Override
    public int compare(Process process, Process t1) {
        return process.getArrivalTime() - t1.getArrivalTime();
    }
}
