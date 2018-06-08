package com.os;

import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        System.out.println("===================== SJF Scheduling =====================");
        _1_();
        System.out.println('\n');
        System.out.println("===================== Round Robin Scheduling =====================");
        _2_();
        System.out.println("=====================                  =====================");
        _3_();
        System.out.println("===================== AG Scheduling =====================");
        _4_();
        System.out.println("=====================                =====================");
    }

    public static void _1_(){
        List<Process> processes = Arrays.asList(
                new SRTFProcess("P1", 0, 7),
                new SRTFProcess("P2", 2, 4),
                new SRTFProcess("P4", 5, 4),
                new SRTFProcess("P3", 4, 1));

        SRTF srtf = new SRTF(processes);
        srtf.run();
    }
    public static void _2_(){
        int qTime = 20;
        List<Process> processes = Arrays.asList(
                new RRProcess("P1", 0, 53),
                new RRProcess("P2", 1, 17),
                new RRProcess("P3", 2, 68),
                new RRProcess("P4", 3, 24));

        RR rr = new RR(processes, qTime);
        rr.run();
    }
    public static void _3_(){
        List<Process> processes = Arrays.asList(
                new PSProcess("P1", 0, 10, 3),
                new PSProcess("P2", 0, 1 , 1),
                new PSProcess("P3", 0, 2 , 4),
                new PSProcess("P4", 0, 1 , 5),
                new PSProcess("P5", 0, 5 , 2) );

        PriorityScheduling ps = new PriorityScheduling(processes);
        ps.run();
    }

    public static void _4_() {
        List<Process> processes = Arrays.asList(
                new AGProcess("P1", 0, 17,7),
                new AGProcess("P2", 2, 6, 9),
                new AGProcess("P3", 5, 11, 4),
                new AGProcess("P4", 15, 4, 2));
        AGScheduling ag = new AGScheduling(processes);
        ag.run();
    }


}
