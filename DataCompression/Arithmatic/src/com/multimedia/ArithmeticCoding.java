package com.multimedia;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class ArithmeticCoding {

    private ArrayList<Pair> commProb;
    private Scanner scanner;
    private int charCounter = 0;

    public ArithmeticCoding() { }

    public void Compress(String filePath) throws IOException{
        scanner = new Scanner(filePath);
        commProb = CalculateCumulativeRange();

        float low   = 0f;
        float high  = 1f;
        float range = 1f;

        char c;
        float plow;
        while( (c = scanner.getNextChar()) != 0 ){
            plow = low;
            low  = low  + range * LowerRange(c);
            high = plow + range * UpperRange(c);
            range = high - low;            
        }        
        //write to file
        String distName = filePath.substring(0, filePath.indexOf('.'))+"Com.txt";
        try(BufferedWriter bw = Files.newBufferedWriter(Paths.get(distName))){
            bw.write(charCounter);
            bw.write( commProb.size() );
            for( Pair p : commProb){
                bw.write( p.sym + " " + p.count + "\n");
            }
            Double value = (0.5*range + low);
            bw.write( value.toString() );
        }catch ( IOException ex){
            System.out.println(ex.getMessage());
        }
    }

    public void Decompress( String filePath ) throws IOException{
        //read from file
        commProb = new ArrayList<>();
        float value = 0;
        try(BufferedReader br = Files.newBufferedReader(Paths.get(filePath))){
            charCounter = br.read();
            int size = br.read();
            for( int i = 0; i < size; i++){
                String line = br.readLine();
                commProb.add( new Pair( line.charAt(0), Float.parseFloat(line.substring(2) ) ) );
            }
            value = Float.parseFloat(br.readLine());
        }catch ( IOException ex){
            System.out.println(ex.getMessage());
        }

        float curValue = value;
        StringBuilder sb = new StringBuilder();

        float low   = 0f;
        float high  = 1f;
        float range = 1f;

        char c;
        float plow;
                
        while( charCounter > 0 ){
            c = getCharByValue(curValue);
            sb.append( c );

            plow = low;
            low  = low  + range * LowerRange(c);
            high = plow + range * UpperRange(c);
            range = high - low;

            curValue = (value-low)/(range);
            charCounter--;
        }
        
        //write to file
        String distName = filePath.substring(0, filePath.indexOf('.'))+"DeCom.txt";
        try(BufferedWriter bw = Files.newBufferedWriter(Paths.get(distName))){
            bw.write( sb.toString() );
        }catch ( IOException ex){
            System.out.println(ex.getMessage());
        }
    }

    private ArrayList<Pair> CalculateCumulativeRange(){
        int[] countingArr = new int[128];
        char c;
        while( (c = scanner.getNextChar()) != 0){
            countingArr[c]++;
            charCounter++;
        }
        ArrayList<Pair> counting = new ArrayList<>();
        for(int i = 0; i < 128; i++){
            if(countingArr[i] != 0){
                counting.add( new Pair( (char)i , countingArr[i]) );
            }
        }
        counting.sort(Pair::compareTo);
        float prev = 0f;
        for(Pair p : counting){
            p.count = p.count/charCounter;
            p.count = p.count + prev;
            prev = p.count;
        }
        scanner.reload();
        return counting;
    }

    private float LowerRange(char c){
        for(int i = 1; i < commProb.size(); i++){
            if( commProb.get(i).sym == c ){
                return commProb.get(i-1).count;
            }
        }
        return 0;
    }
    private float UpperRange(char c){
        for (Pair aCommProb : commProb) {
            if (aCommProb.sym == c) {
                return aCommProb.count;
            }
        }
        return 0;
    }
    private char  getCharByValue(float value){
        for(Pair p : commProb){
            if( p.count > value ){
                return p.sym;
            }
        }
        return 0;
    }
}

class Pair implements Comparable<Pair>{
    char sym;
    float  count;
    public Pair(char c, int count){
        sym = c; this.count = count;
    }
    public Pair(char c, float count){
        sym = c; this.count = count;
    }

    @Override
    public int compareTo(Pair o) {
        return (int)(o.count - this.count);
    }
    @Override
    public String toString() {
        return sym + ": " + count;
    }
}