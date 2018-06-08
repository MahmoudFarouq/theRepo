package com.multimedia;

import java.io.IOException;

public class AHC {

    AHCTree tree;
    public AHC() {}

    public String Compress(String filePath) throws IOException{
        Scanner scanner = new Scanner(filePath);
        tree = new AHCTree();
        String compressed = "";
        char curChar;
        while((curChar = scanner.getNextChar()) != 0){
            tree.addNode(curChar + "");
        }
        scanner.reload();
        while((curChar = scanner.getNextChar()) != 0){
            compressed += tree.getCode(curChar + "");
        }
        return compressed;
    }

    public String Decompress(String filePath) throws IOException{
        Scanner scanner = new Scanner(filePath);
        StringBuilder sb = new StringBuilder();
        char curChar;
        String curCode = "";
        while((curChar = scanner.getNextChar()) != 0){
            curCode += curChar+"";
            String test = tree.isCODE(curCode);
            if( test != null){
                sb.append(test);
                curCode = "";
            }
        }
        return sb.toString();
    }

}
