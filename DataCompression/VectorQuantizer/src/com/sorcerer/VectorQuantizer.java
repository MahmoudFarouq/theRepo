package com.sorcerer;

import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;

import static com.sorcerer.Main.blockLingth;

class Block implements Comparator<Block> {
    int matrix[][];
    int distanceFromZero = 0;
    int rows;
    int columns;

    public Block(int blockLingth){
        matrix = new int[blockLingth][blockLingth];
        rows = blockLingth;
        columns = blockLingth;
    }

    // the euclidean distance from matrix to the zero matrix
    public void calculateDistance(){
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                distanceFromZero += ( matrix[row][column] )*( matrix[row][column] );
            }
        }
        distanceFromZero = (int)Math.sqrt(distanceFromZero);
    }

    // matrix + number
    public Block add(int num){
        Block m = new Block(blockLingth);
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                m.matrix[row][column] = matrix[row][column] + num;
            }
        }
        return m;
    }

    // matrix - number
    public Block sub(int num){
        Block m = new Block(blockLingth);
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                m.matrix[row][column] = matrix[row][column] - num;
            }
        }
        return m;
    }

    @Override
    public int compare(Block block, Block t1) {
        return block.distanceFromZero - t1.distanceFromZero;
    }
}


class CompressOutput{
    ArrayList<Block> codeBook;
    int[][] compressed;
    CompressOutput(ArrayList<Block> codeBook, int[][] compressed){
        this.codeBook = codeBook;
        this.compressed = compressed;
    }
}


class Node{
    Node left , right  ;
    ArrayList<Block> blockList ;
    int blockLingth;
    Block avg = null ;
    Node (int bl) {
        left = right = null ;
        blockList = new ArrayList<Block>();
        avg = new Block(bl);
    }
    public void calculateAverage(){
        for(Block b : blockList){
            for(int row = 0; row < b.rows; row++){
                for(int column = 0; column < b.columns; column++){
                    avg.matrix[row][column] += ( b.matrix[row][column] );
                }
            }
        }
        if( blockList.size() == 0 )
            return;
        for(int row = 0; row < avg.rows; row++){
            for(int column = 0; column < avg.columns; column++){
                avg.matrix[row][column] /= blockList.size();
            }
        }
    }
}


public class VectorQuantizer {
    int blockLingth;
    public VectorQuantizer(int bl){
        blockLingth = bl;
    }

    public CompressOutput compress (ArrayList<Block> blockList, int codeBookSize) {

        // transform the ArrayList<Block> int a 2d block matrix
        Block[][] blockMatrix = ListToMatrix(blockList);

        Node root = new Node(blockLingth);
        root.blockList = blockList;
        root.calculateAverage();

        ArrayList<Node> nodes = Distribute(root, codeBookSize);
        ArrayList <Block> codeBook = new ArrayList<Block>() ;

        for (Node node : nodes) {
            node.calculateAverage();
            node.avg.calculateDistance();
            codeBook.add(node.avg);
        }

        // replace every block with it's corresponding block from code book
        int[][] compressed = new int[400/blockLingth][400/blockLingth];
        for(int i=0 ; i<400/blockLingth ; i++) {
            for(int j=0 ; j<400/blockLingth; j++) {
                int minDistanceNodeIndex = 0;
                int minDistance = 10000;
                for(int n = 0; n < codeBook.size(); n++){
                    if( Math.abs(blockMatrix[i][j].distanceFromZero - codeBook.get(n).distanceFromZero) < minDistance){
                        minDistanceNodeIndex = n;
                        minDistance = Math.abs(blockMatrix[i][j].distanceFromZero - codeBook.get(n).distanceFromZero);
                    }
                }
                compressed[i][j] = minDistanceNodeIndex;
            }
        }

        return new CompressOutput(codeBook, compressed);
    }

    public int[][] decompress (CompressOutput co) {

        // for every block in QS, replace is with the corresponding block from code block
        ArrayList <Block> codeBook = co.codeBook   ;
        int[][] QS = co.compressed ;
        int[][] decompressed = new int[400][400];
        for (int i = 0 ; i< 400/blockLingth; i++ ) {
            for (int j=0 ; j < 400/blockLingth ; j++ ) {
                Block b = codeBook.get(QS[i][j]);
                for(int r = 0; r < blockLingth; r++){
                    for(int c = 0; c < blockLingth; c++){
                        decompressed[i*blockLingth+r][j*blockLingth+c] = b.matrix[r][c];
                    }
                }
            }
        }
        return decompressed;
    }

    public ArrayList<Node> Distribute (Node root , int codeBookSize) {
        ArrayList<Block> fullBlockList = root.blockList;
        ArrayList<Node> nodes = new ArrayList<Node>();
        nodes.add(root);
        while( nodes.size() < codeBookSize ){
            ArrayList<Node> newNodes = new ArrayList<Node>();
            for(Node node : nodes){
                node.calculateAverage();
                node.left  = new Node(blockLingth);            node.left.avg = node.avg.sub(1);
                node.right = new Node(blockLingth);            node.right.avg = node.avg.add(1);
                newNodes.add(node.left);            newNodes.add(node.right);
                node.left.calculateAverage();       node.right.calculateAverage();
                node.left.avg.calculateDistance();  node.right.avg.calculateDistance();
            }
            for(Block block : fullBlockList){
                int minDistanceNodeIndex = 0;
                int minDistance = 10000;
                for(int n = 0; n < newNodes.size(); n++){
                    if( Math.abs(newNodes.get(n).avg.distanceFromZero - block.distanceFromZero) < minDistance){
                        minDistanceNodeIndex = n;
                        minDistance = Math.abs(newNodes.get(n).avg.distanceFromZero - block.distanceFromZero);
                    }
                }
                newNodes.get(minDistanceNodeIndex).blockList.add(block);
            }
            nodes = newNodes;
        }
        return nodes;
    }
    public Block[][] ListToMatrix(List<Block> blockList){
        Block[][] blockMatrix = new Block[400/blockLingth][400/blockLingth];
        int x = 0;
        int y = 0;
        for(int i = 0; i < (400/blockLingth)*(400/blockLingth) ; i++){
            blockMatrix[y][x] = blockList.get(i);
            blockMatrix[y][x].calculateDistance();
            x++;
            y += x/(400/blockLingth);
            x %= (400/blockLingth);
        }
        return blockMatrix;
    }

}