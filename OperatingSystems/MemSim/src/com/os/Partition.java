package com.os;

enum STATUS{FREE, OCCUPIED}


class Partition {
    private int pAddress;
    private int pSize;
    private STATUS status;

    Partition(int address, int size){
        pAddress = address;
        pSize = size;
        status = STATUS.FREE;
    }

    STATUS getStatus() {
        return status;
    }
    void setStatus(STATUS status) {
        this.status = status;
    }

    int getPartitionAddress() {
        return pAddress;
    }
    void setPartitionAddress(int address) {
        pAddress = address;
    }
    int getPartitionSize() {
        return pSize;
    }
    void setPartitionSize(int size) {
        pSize = size;
    }


    @Override
    public String toString(){
        return "{Address: " + pAddress + ", Size: " + pSize + ", Status: " + status + "}\n";
    }
}
