package com.multimedia;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Scanner {

    private String stream = null;
    private int curIndex = -1;

    public Scanner(String filePath) throws IOException{
        this.stream = getText(filePath);
    }

    public char getNextChar(){
        curIndex++;
        if(curIndex >= stream.length())
            return 0;
        return stream.charAt(curIndex);
    }

    public void reload(){
        curIndex = -1;
    }

    private String getText(String filePath) throws IOException {
        StringBuilder sb = new StringBuilder();
        try(BufferedReader reader = Files.newBufferedReader(Paths.get(filePath))){
            String line = reader.readLine();
            do{
                sb.append(line);
                line = reader.readLine();
            }
            while(line != null);
        }
        return sb.toString();
    }

}
