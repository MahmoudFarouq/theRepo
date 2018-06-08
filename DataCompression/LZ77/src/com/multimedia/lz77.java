package com.multimedia;

import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.ByteBuffer;
import java.util.ArrayList;

class Tag{

    public static final int CHAR = 8;
    public static int lenOfNumInBin(int num){return Integer.toBinaryString(num).length();}

    private int pointer;
    private int length;
    private char nextChar;

    public void setPointer(int pointer) {
        this.pointer = pointer;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setNextChar(char nextChar) {
        this.nextChar = nextChar;
    }

    public int getPointer() {
        return pointer;
    }

    public int getLength() {
        return length;
    }

    public char getNextChar() {
        return nextChar;
    }

    public Tag(){ }
    public Tag(int ptr, int len, char nxt){pointer=ptr; length=len; nextChar=nxt; }

    public Tag copy(){return new Tag(pointer, length, nextChar);}

    public int getInt(int maxPtr, int maxLength){
        Integer result = pointer;
        result = result << lenOfNumInBin(maxLength);
        result += length;
        result = result << CHAR;
        result += nextChar;
        return result;
    }

    public void setAttr(int theNum, int maxPtr, int maxLength){
        nextChar = (char)(theNum - ((theNum >> CHAR) << CHAR));
        int temp = theNum >> CHAR;
        length   = temp - (( temp >> lenOfNumInBin(maxLength)) << lenOfNumInBin(maxLength));
        pointer  = temp >> lenOfNumInBin(maxLength);
    }

    @Override
    public String toString(){
        return ("<ptr: "+pointer+"; len: "+length+"; nxt: "+nextChar+">\n");
    }
}

class lz77{
    private int MAX_LEN = 0;
    private int MAX_PTR = 0;
    private int MAX_GO_BACK = 10;

    public lz77(){}

    public void Compress(String filePath, JTextArea ta) throws IOException {

        String stream = getText(filePath);
        stream = stream.substring(0, stream.length()-4);        //to remove the null

        ArrayList<Tag> tagArray = new ArrayList<>();		// to carry the tags in
        String curStr = null;

        int curIndex = 0;									// current index in the stream
        int lenOfSubStr = 1;								// len of substr i'm working on
        int prevLastOccur = -1;								// the last time i saw that substr

        while(curIndex+lenOfSubStr <= stream.length()){
            curStr = stream.substring(curIndex, curIndex+lenOfSubStr);				// substring to work on
            int lastOccur = stream.lastIndexOf(curStr, curIndex-curStr.length());	// seaarch for it by going back
            if(lastOccur != -1 && (curIndex-lastOccur) < MAX_GO_BACK){				// if seen before and it's not too far
                if( lastOccur + curStr.length() == curIndex 						// there is repetetion
                        && lastOccur + curStr.length() < stream.length()-1){				// and i'm not at the end yet

                    lenOfSubStr = goOverRepeatition(curIndex, stream, curStr, lenOfSubStr);

                    if(curIndex+lenOfSubStr < stream.length()) lenOfSubStr++;		// if not yet finished the stream, add the (nextChar)
                    prevLastOccur = curIndex - curStr.length();
                }else{															// normal tag
                    lenOfSubStr++;												// increase len of substr
                    prevLastOccur = lastOccur;									// update the last time i saw it
                }
            }else {										// otherwise
                setTagValues(prevLastOccur, curIndex, curStr, tagArray);
                curIndex += curStr.length();							// increase cuIndex with the len of processed substring
                lenOfSubStr = 1;										// reset to 1
                prevLastOccur = -1;
                curStr = null;								// reset to -1
            }
        }
        setTagValues(prevLastOccur, curIndex, curStr, tagArray);

        for(Tag t : tagArray){
            ta.append( t.toString() );
        }

        byte[] bytes = toByteArray(tagArray);
        String outputPath = Paths.get(filePath.substring(0, filePath.indexOf(".")))+"Com.txt";
        FileOutputStream fos = new FileOutputStream(outputPath);
        fos.write(MAX_LEN);
        fos.write(MAX_PTR);
        fos.write(bytes);
        fos.close();
    }

    private int goOverRepeatition(int curIndex, String stream, String curStr, int lenOfSubStr){
        int firstIndex  = curIndex;
        int secondIndex = firstIndex + curStr.length();
        while(stream.substring(firstIndex, secondIndex).equals(curStr)){
            firstIndex  += curStr.length();
            secondIndex += curStr.length();
            lenOfSubStr += curStr.length();
            if(secondIndex >= stream.length()){
                lenOfSubStr -= curStr.length();
                break;
            }
        }
        return lenOfSubStr;
    }

    private void setTagValues(int prevLastOccur, int curIndex, String curStr, ArrayList<Tag> tagArray){
        if(curStr == null)
            return;
        Tag uniTag = new Tag();								// universal tag, to use everywhere
        if (prevLastOccur == -1) {        		// didnt come before, any of the substring
            uniTag.setPointer(0);				// make the pointer 0
        } else {
            uniTag.setPointer(curIndex - prevLastOccur);	// give it the num to go back
        }
        uniTag.setLength(curStr.length() - 1);				// te length to read
        uniTag.setNextChar(curStr.charAt(curStr.length() - 1));	// the next character

        tagArray.add(uniTag.copy());							// add copy of unitag to tagArray

        MAX_PTR = (uniTag.getPointer() > MAX_PTR ? uniTag.getPointer():MAX_PTR);	// update
        MAX_LEN = (uniTag.getLength()  > MAX_LEN ? uniTag.getLength() :MAX_LEN);	// update
    }

    private byte[] toByteArray(ArrayList<Tag> tagArray){
        // the tagArray is ready to be processed, from tags to bytes

        int arraySize = tagArray.size();							// size of tagArray
        int bitMaxLen = Tag.lenOfNumInBin(MAX_LEN);					// max bits for len in tag
        int bitMaxPtr = Tag.lenOfNumInBin(MAX_PTR);					// max bits for ptr in tag

        // the max number of bytes to reserve for single tag
        int MaxByteForNum = ((bitMaxLen+bitMaxPtr+Tag.CHAR) % 8 == 0 ?
                (bitMaxLen+bitMaxPtr+Tag.CHAR) / 8:(bitMaxLen+bitMaxPtr+Tag.CHAR) / 8 +1);

        int BufferSize = MaxByteForNum*arraySize;			// the size of buffer to put bytes in
        byte[] bytes = new byte[BufferSize];				// the buffer
        for (int i = 0; i < arraySize; i++) {				// for every tag
            int tracer = MaxByteForNum*(i+1)-1;				// trace the movement in the buffer
            Integer theNum = tagArray.get(i).getInt(MAX_PTR, MAX_LEN);		// convert the whole tag to an int
            for (int j = 0; j < MaxByteForNum; j++) {						// for every (8 bits) in theNum

                // isolate or extract the right 8 bits in the int
                int mask = ( 1 << Tag.CHAR) - 1;
                byte currByte = (byte)(theNum & mask);
                currByte &= 0xff;		// to make it unsigned

                theNum = theNum >> Tag.CHAR;	// right shift, to redo the process on the next (8 bits)
                bytes[tracer--] = currByte;		// we are going back to put bytes, and forward to put tags
            }
        }
        return bytes;
    }

    private String getText(String filePath) throws IOException{
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

    private byte[] getBytes(String filePath) throws IOException{
        byte[] bytes = null;
        try(BufferedReader reader = Files.newBufferedReader(Paths.get(filePath))){
            bytes = Files.readAllBytes(Paths.get(filePath));
        }
        return bytes;
    }

    public void Decompress(String filePath, JTextArea ta)throws IOException{
        byte[] bytes = getBytes(filePath);
        ArrayList<Integer> tagAsInt = new ArrayList<>();
        MAX_LEN = bytes[0]; MAX_PTR = bytes[1];

        int numOfBytesPerTag = 2;

        for (int i = 2; i < bytes.length; i+=numOfBytesPerTag) {
            Integer theNum = 0;
            for (int j = 0; j < numOfBytesPerTag; j++) {
                theNum = theNum << Tag.CHAR;
                theNum += bytes[i+j];
            }
            tagAsInt.add(theNum);
        }
        Tag uniTag = new Tag();
        String stream = "";
        int tracer = 0;
        for(int i = 0; i < tagAsInt.size(); i++){
            uniTag.setAttr(tagAsInt.get(i), MAX_PTR, MAX_LEN);
            ta.append(uniTag.toString());
            String subStr = null;
            if(uniTag.getLength() > uniTag.getPointer()){		//DECOMPRESS repeated
                String sub = stream.substring(tracer-uniTag.getPointer(), stream.length());
                subStr = "";
                for(int t = 0; t < uniTag.getLength(); t+=uniTag.getPointer()){
                    subStr += sub;
                }
            }else{
                subStr = stream.substring(tracer-uniTag.getPointer(),
                        tracer-uniTag.getPointer()+uniTag.getLength());
            }
            subStr += uniTag.getNextChar();
            stream += subStr;
            tracer += subStr.length();
        }
        ta.append(stream);
        String outputPath = Paths.get(filePath.substring(0, filePath.indexOf(".")))+"Decom.txt";
        try(BufferedWriter bw = Files.newBufferedWriter(Paths.get(outputPath))){
            bw.write(stream);
        }catch (IOException ex){
            System.out.println(ex.getMessage());
        }
    }
}