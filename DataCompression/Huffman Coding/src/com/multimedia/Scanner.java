package com.multimedia;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Scanner {

    private String stream = null;
    private int curIndex = -1;

    public Scanner(String filePath) throws IOException{
        this.stream = filePath; //getText(filePath);
    }

    public char getNextChar(){
        curIndex++;
        if(curIndex >= stream.length())
            return 0;
        return stream.charAt(curIndex);
    }

    private String getText(String filePath) throws IOException {
        StringBuilder sb = new StringBuilder();
        try(BufferedReader reader = Files.newBufferedReader(Paths.get(filePath))){
            String line = null;
            do{
                line = reader.readLine();
                sb.append(line);
            }
            while(line != null);
        }
        return sb.toString();
    }

    public void reload(){
        curIndex = -1;
    }

}
