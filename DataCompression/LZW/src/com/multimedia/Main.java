package com.multimedia;

import javax.swing.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Main {

    public static void main(String[] args) {
	// write your code here
        JFrame ioframe = new JFrame("IOFrame");
        ioframe.setContentPane(new IOForm().panel1);
        ioframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ioframe.pack();
        ioframe.setVisible(true);
    }
}

class lzw{
    private Map<String, Integer> CmyDict;
    private Map<Integer, String> DmyDict;

    public lzw(){
        InitializeDect();
    }

    public void Compress(String filePath, JTextArea ta) throws IOException{

        String stream = getText(filePath);
        ta.append("the Original Text is: \n");
        ta.append(stream+"\n\n");

        LinkedList<Integer> output = new LinkedList<>();

        int curIndex = 0;
        String P     = "";
        char   c;

        while(curIndex < stream.length()){
            c = stream.charAt(curIndex++);
            String temp = P+c;

            if( CmyDict.containsKey(temp) ){
                P = temp;
            }else{
                CmyDict.put(temp, CmyDict.size()+1);
                output.add( CmyDict.get( P ) );
                P = c + "";
            }
        }
        output.add( CmyDict.get( P ) );

        String newFile = filePath.substring(0, filePath.indexOf('.'))+"(Compressed).txt";

        try (BufferedWriter writer = Files.newBufferedWriter(Paths.get(newFile))){
            writer.write( output.size() );
            ta.append("After Compression: \n");
            System.out.println("Size: "+output.size());
            for(Integer x : output) {
                writer.write(x);
                ta.append(x+" ");
            }
        }catch (IOException ex){
            ex.printStackTrace();
        }

    }

    public void Decompress(String filePath, JTextArea ta) throws IOException{
        LinkedList<Integer> data = getData(filePath);

        ta.append("Before Decompression: \n");
        for(Integer x : data) {
            ta.append(x+" ");
        }
        ta.append("\n\n");

        StringBuilder sb = new StringBuilder();
        String P = "";
        char   c;

        int curIndex = 0;
        int curWord = data.get(curIndex);
        int preWord = -1;

        sb.append(DmyDict.get( curWord ));

        while(curIndex < data.size()-1){

            preWord = curWord;
            curWord = data.get(++curIndex);
            String scurWord = DmyDict.get( curWord );
            String spreWord = DmyDict.get( preWord );

            if( DmyDict.containsValue(scurWord) ){
                sb.append(scurWord);
                P = spreWord;
                c = scurWord.charAt(0);
                DmyDict.put(DmyDict.size()+1, P+c);
            }else{
                P = spreWord;
                c = spreWord.charAt(0);
                sb.append(P+c);
                DmyDict.put(DmyDict.size()+1, P+c);
            }
        }

        //write the whole string to the file
        String newFile = filePath.substring(0, filePath.indexOf('.'))+"(Decompressed).txt";
        try (BufferedWriter writer = Files.newBufferedWriter(Paths.get(newFile))){
            writer.write(sb.toString());
            ta.append("After Decompression: \n"+sb.toString());
        }catch (IOException ex){
            ex.printStackTrace();
        }
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
        String stream = sb.toString();
        return stream.substring(0, stream.length()-4);  //to remove the null
    }

    private LinkedList<Integer> getData(String filePath) throws IOException{
        //reads the whole linked list from the file
        LinkedList<Integer> lst = new LinkedList<>();
        //ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(filePath));
        //obj = (LinkedList<Integer>) inputStream.readObject();

        try (BufferedReader reader = Files.newBufferedReader(Paths.get(filePath))){
            int size = reader.read();
            while( size-- > 0 ){
                lst.add( reader.read() );
            }
        }catch (IOException ex){
            ex.printStackTrace();
        }
        return lst;
    }

    private void InitializeDect(){
        CmyDict = new TreeMap<>();
        DmyDict = new TreeMap<>();
        for(int i = 0; i < 127; i++) {
            CmyDict.put(((char) i) + "", i);
            DmyDict.put(i, ((char) i) + "");
        }
    }
}
