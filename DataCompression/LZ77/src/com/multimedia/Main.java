package com.multimedia;

import javax.swing.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException{

        JFrame ioframe = new JFrame("IOFrame");
        ioframe.setContentPane(new IOForm().panel1);
        ioframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ioframe.pack();
        ioframe.setVisible(true);

       /*//System.out.println( System.getProperty("user.dir") );
        /*String stream = "abaababababababababa";
        //String stream = "abaababaabbbbbbbbbbbba";

        String path    = "/home/sorcerer/Desktop/file.txt";
        String newPath = path.substring(0, path.indexOf("."))+"Com.txt";
        lz77 lz = new lz77();
        //lz.Compress(path);
        lz.Decompress(newPath);*/

    }


}





