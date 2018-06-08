package com.os;

import java.util.LinkedList;

enum POLICY{FIRST_FIT, BEST_FIT, WORST_FIT}
enum DEFRAGMENT_CASE{CASE_1, CASE_2, CASE_3}

class MemSim {
    private LinkedList<Partition> partitions;

    MemSim(int initSize){
        partitions = new LinkedList<>();
        partitions.add( new Partition(0, initSize) );
    }

    int Allocate(int neededSize, POLICY allocationPolicy){
        Partition bestPartition = null;
        int bpIndex = -1;
        for (int i = 0; i < partitions.size(); i++) {
            Partition p = partitions.get(i);
            if (p.getStatus() == STATUS.FREE && p.getPartitionSize() >= neededSize) {
                if (bestPartition == null) {
                    bestPartition = p;
                    bpIndex = i;
                } else if ( (allocationPolicy == POLICY.BEST_FIT
                            && p.getPartitionSize() < bestPartition.getPartitionSize())
                         || (allocationPolicy == POLICY.WORST_FIT
                            && p.getPartitionSize() > bestPartition.getPartitionSize())) {
                    bestPartition = p;
                    bpIndex = i;
                } else if ( allocationPolicy == POLICY.FIRST_FIT ) {
                    bestPartition = p;
                    bpIndex = i;
                    break;
                }
            }
        }
        // if no available partition
        if(bestPartition == null){
            return -1;
        }
        // there is..
        int oldSize = bestPartition.getPartitionSize();
        bestPartition.setStatus(STATUS.OCCUPIED);
        bestPartition.setPartitionSize( neededSize );
        if(oldSize-neededSize > 0){
            int newPpos  = bestPartition.getPartitionAddress() + bestPartition.getPartitionSize();
            int newPsize = oldSize - neededSize;
            partitions.add(bpIndex+1, new Partition( newPpos, newPsize ));
        }
        return bestPartition.getPartitionAddress();
    }

    int Deallocate(int partitionAddress){
        for (Partition p : partitions) {
            if (p.getPartitionAddress() == partitionAddress && p.getStatus() == STATUS.OCCUPIED) {
                p.setStatus( STATUS.FREE );
                return 1;
            }
        }
        return -1;
    }

    void Defragment(DEFRAGMENT_CASE d_case){
        switch (d_case){
            case CASE_1:
                // i'm already doing this in Allocate;
                break;
            case CASE_2:
                _defrag_case2();
                break;
            case CASE_3:
                _defrag_case3();
                break;
        }
    }
    private void _defrag_case2(){
        for (int i = 0; i < partitions.size()-1; i++) {
            Partition p1 = partitions.get(i);
            Partition p2 = partitions.get(i+1);
            if (p1.getStatus() == STATUS.FREE && p2.getStatus() == STATUS.FREE ) {
                p1.setPartitionSize( p1.getPartitionSize() + p2.getPartitionSize() );
                partitions.remove(i+1);
                i--;
            }
        }
    }
    private void _defrag_case3(){
        int totalFreeSize = 0;
        for (int i = 0; i < partitions.size(); i++) {
            Partition p = partitions.get(i);
            if (p.getStatus() == STATUS.FREE ) {
                totalFreeSize += p.getPartitionSize();
                partitions.remove(i);
            }
        }
        //update partitions;
        int newPos  = 0;
        for (Partition p : partitions) {
            p.setPartitionAddress(newPos);
            newPos += p.getPartitionSize();
        }
        if(totalFreeSize != 0) {
            partitions.add(new Partition( newPos, totalFreeSize ));
        }
    }

    void memoryStatus(){
        if( partitions.isEmpty() ){
            System.out.println( "Empty Memory\n" );
            return;
        }
        int i = 1;
        for(Partition p : partitions){
            System.out.println("Partition " + i++ + ": " + p);
        }
    }
}
