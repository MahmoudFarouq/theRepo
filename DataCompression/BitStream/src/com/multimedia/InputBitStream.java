package com.multimedia;

import java.io.*;
import java.util.LinkedList;

public class InputBitStream {
    private LinkedList<Integer>  integers;
    private int    size;
    private int    curBit  = 0;
    private int    curInt = 0;
    private int    lastInt= 0;     //len of last byte in the array

    public InputBitStream(String filePath) throws IOException {
        File f = new File(filePath);
        integers = new LinkedList<>();
        if( f.exists() ){
            System.out.println( "Opening File: "+filePath );
        }else{
            throw( new IOException("File Doesn't Exist") );
        }
        readData(filePath);
        size = integers.size();
        lastInt = integers.get(0);
        curInt++;
        int last = integers.get(size-1);
        last = last << (32 - lastInt);
        integers.set(size-1, last);
    }
    private void readData(String filePath) throws IOException{
        FileInputStream file = new FileInputStream(filePath);
        DataInputStream is   = new DataInputStream(file);
        int x;
        do{
            try {
                x = is.readInt();
                integers.add(x);
            }catch (EOFException ex){
                break;
            }
        } while( true );
        is.close();
        file.close();
    }

    public int getNextBit(){
        curBit++;
        if(curInt == size-1 && curBit > lastInt){
            return -1;
        }
        if(curBit > 32){
            curBit = 1;
            curInt++;
        }
        if(curInt == size) return -1;
        return ( (1 << (32 - curBit) & integers.get(curInt)) == 0 ? 0:1 );
    }
}