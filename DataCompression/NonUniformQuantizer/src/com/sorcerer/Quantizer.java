package com.sorcerer;

import java.util.ArrayList;
import java.util.List;

class CompressOutput{
    ArrayList<Integer> Ranges, Qs;
    CompressOutput(ArrayList<Integer> Ranges, ArrayList<Integer> Qs){
        this.Ranges = Ranges;
        this.Qs = Qs;
    }
}


public class Quantizer {
    private ArrayList <Integer> averages = new ArrayList<Integer>() ;
    ArrayList <Integer> pixelsList = new ArrayList<Integer>() ;
    int numberOfBits;

    public CompressOutput compress () {
        Node root = new Node();
        int numOfLevels = (int) Math.pow(2, this.numberOfBits);
        root.pixelsList = this.pixelsList;

        ArrayList<Node> nodes = Distribute(root, numOfLevels);
        for (int j=0 ; j<nodes.size() ; j ++ ) {
            averages.add( nodes.get(j).avg );
        }

        List<Integer> Last = averages.subList(averages.size() - numOfLevels, averages.size());

        ArrayList<Integer> Ranges = new ArrayList<Integer>();
        Ranges.add(0);
        for (int i = 0; i < Last.size() - 1; i++) {
            int temp = (Last.get(i) + Last.get(i + 1)) / 2;
            Ranges.add(temp);
        }
        Ranges.add(127);

        ArrayList <Integer> Qs = new ArrayList<Integer>() ;
        for (int i=0 ; i<this.pixelsList.size() ; i++ ) {
            for (int j=0 ; j<Ranges.size() ; j ++ ) {
                if (pixelsList.get(i) < Ranges.get(j)){
                    Qs.add(j-1) ;
                    break;
                }
            }
        }
        return new CompressOutput(Ranges, Qs);
    }


    public ArrayList <Integer> decompress (CompressOutput co) {
        ArrayList <Integer> Last = co.Ranges   ;
        ArrayList <Integer> QS = co.Qs ;
        ArrayList <Integer> output = new ArrayList <Integer>() ;
        for (int i = 0 ; i< QS.size() ; i++ ) {
            for (int j=0 ; j<Last.size() ; j++ ) {
                if (QS.get(i) == j ) {
                    output.add (Last.get(j)) ;
                    break;
                }
            }
        }
        return output;
    }

    public ArrayList<Node> Distribute (Node root , int NumOfLevels) {
        ArrayList<Node> nodes = new ArrayList<Node>();
        nodes.add(root);
        int numOfnodes = NumOfLevels;
        while( nodes.size() < numOfnodes ){
            ArrayList<Node> newNodes = new ArrayList<Node>();
            for(Node node : nodes){
                int a = node.avg - 1 ;
                int b = node.avg + 1 ;
                node.left = new Node () ; node.right = new Node () ;
                for (int i = 0 ; i< node.pixelsList.size() ; i++ ) {
                    int temp1 , temp2 ;
                    temp1 = Math.abs(a- node.pixelsList.get(i)) ;
                    temp2 = Math.abs(b- node.pixelsList.get(i)) ;
                    if (temp2 > temp1) {
                        node.left.pixelsList.add(node.pixelsList.get(i)) ;
                    }else {
                        node.right.pixelsList.add(node.pixelsList.get(i)) ;
                    }
                }
                if (node.left.pixelsList.size() == 0 ) {
                    node.left.avg = node.avg ;
                }else {
                    int sumLeft = 0 ;
                    for (int i = 0 ; i < node.left.pixelsList.size() ; i++ ) {
                        sumLeft+= node.left.pixelsList.get(i) ;
                    }
                    node.left.avg = sumLeft/node.left.pixelsList.size() ;
                }
                if (node.right.pixelsList.size() == 0 ) {
                    node.right.avg = node.avg ;
                }else {
                    int sumRight = 0 ;
                    for (int i = 0 ; i < node.right.pixelsList.size() ; i++ ) {
                        sumRight+= node.right.pixelsList.get(i) ;
                    }
                    node.right.avg = sumRight/node.right.pixelsList.size() ;
                }
                newNodes.add(node.left); newNodes.add(node.right);
            }
            nodes = newNodes;
        }
        return nodes;
    }
}

class Node {
    Node left , right  ;
    ArrayList<Integer> pixelsList ;
    int avg = 0 ;
    Node () {
        left = right = null ;
        pixelsList = new ArrayList<Integer>() ;
    }
}