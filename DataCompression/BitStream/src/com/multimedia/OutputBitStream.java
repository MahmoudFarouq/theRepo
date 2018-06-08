package com.multimedia;

import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.LinkedList;

public class OutputBitStream {
    private LinkedList<Integer> integers;
    private FileOutputStream file;
    private int    curBit  = 0;
    private int    curInt = 0;

    public OutputBitStream(String fileName) throws IOException{
        file = new FileOutputStream(fileName);
        integers = new LinkedList<>();
        integers.add(0);
    }
    public void add(String x){
        int len = x.length();
        for(int i = 0; i < len; i++){
            put((int)x.charAt(i) - 48 );
        }

    }
    private void put(int digit){
        curBit++;
        if(curBit > 32){
            integers.add(curInt);
            curInt = 0;
            curBit = 1;
        }
        curInt = (curInt << 1) + digit;
    }
    public void flush() throws IOException{
        integers.set(0, curBit);
        integers.add(curInt);
        DataOutputStream os = new DataOutputStream(file);
        for (Integer integer : integers) {
            os.writeInt(integer);
        }
        os.close();
        file.close();
    }
}
