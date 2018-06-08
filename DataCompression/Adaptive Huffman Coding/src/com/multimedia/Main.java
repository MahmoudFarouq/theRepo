package com.multimedia;

import java.io.IOException;
import java.util.LinkedList;

public class Main {

    public static void main(String[] args) {
	// write your code here

        AHC ahc = new AHC();
        try {
            LinkedList<String>lst = ahc.Compress("ABCCCAAAA");
            for(String s : lst){
                System.out.print(s);
            }
            System.out.println();

            String dec = ahc.Decompress("000010010101000101110");
            System.out.println( dec );
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }
}