package com.multimedia;

import java.io.IOException;
import java.util.LinkedList;

public class AHC {

    public AHC() {}

    public LinkedList<String> Compress(String filePath) throws IOException{
        Scanner scanner = new Scanner(filePath);
        AHCTree tree = new AHCTree();
        LinkedList<String> outList = new LinkedList<>();
        char curChar;
        while((curChar = scanner.getNextChar()) != 0){
            outList.add(tree.addNode(curChar + ""));
        }
        return outList;
    }

    public String Decompress(String filePath) throws IOException{
        Scanner scanner = new Scanner(filePath);
        AHCTree tree = new AHCTree();
        StringBuilder sb = new StringBuilder();

        char curChar;
        String curCode = "";
        boolean NYT = true;
        while((curChar = scanner.getNextChar()) != 0){
            curCode += curChar+"";
            String sym  = tree.isCODEfromTree(curCode);
            String sym2 = tree.isCODEfromDict(curCode);
            if(NYT){
                if(sym2 != null){
                    tree.addNode(sym2);
                    sb.append(sym2);
                    NYT = false;
                    curCode = "";
                }
            }else if(tree.isNYT(curCode)){
                NYT = true;
                curCode = "";
            }else if( sym != null ){
                tree.addNode(sym);
                sb.append(sym);
                curCode = "";
            }
        }
        return sb.toString();
    }

}
