package com.multimedia;

import java.io.*;

public class Main {

    public static void main(String[] args) {
	// write your code here
        try {
            String s = "00101111110101001010101111011110101101101111101101001";
            OutputBitStream o = new OutputBitStream("o.txt");
            o.add(s);
            o.flush();
            InputBitStream i = new InputBitStream("o.txt");
            int z;
            do{
                z = i.getNextBit();
                System.out.print(z);
            }while (z != -1);
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }
}