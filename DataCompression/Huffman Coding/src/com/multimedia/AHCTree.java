package com.multimedia;
import java.util.LinkedList;

public class AHCTree {
    private LinkedList<Node> nodesList;

    public AHCTree(){
        nodesList = new LinkedList<>();
        nodesList.add(new Node("rootNode", 0));   //the root
        nodesList.get(0).setParent(null);
    }

    public void addNode(String nodeSymbol){
        Node theParent = getParentOfNode(nodeSymbol);
        if( theParent.nodeWight == 0 ){               // first occurrence, the parent is a NYT node
            addNewNode(theParent, nodeSymbol);
        }
        Node theNode = getNode(nodeSymbol);
        while(theNode != nodesList.get(0)){     // while thenode != root
            for( Node n : nodesList){
                if( theNode.isSwappable(n)){
                    swap(theNode, n);
                    break;
                }
            }
            theNode.nodeWight++;
            theNode = theNode.getParent();
        }
        theNode.nodeWight++;
    }

    public String getCode(String sym){
        return Height( getNode(sym) );
    }

    private void addNewNode(Node theParent, String nodeSymbol){
        Node right = new Node(nodeSymbol, 0);
        Node left  = new Node("NYT", 0);
        theParent.setLeft ( left );  nodesList.add(left);
        theParent.setRight( right ); nodesList.add(right);
        left.setParent(theParent); right.setParent(theParent);
    }
    private void swap(Node theNode, Node n){
        Node nParent = n.getParent();
        Node theNodeParent = theNode.getParent();
        if( nParent.getLeft() == n && theNodeParent.getLeft() == theNode ){ // both on left of parents
            nParent.setLeft(theNode); theNodeParent.setLeft(n);
        }else if( nParent.getRight() == n && theNodeParent.getRight() == theNode ){
            nParent.setRight(theNode); theNodeParent.setRight(n);
        }else if( nParent.getLeft() == n && theNodeParent.getRight() == theNode ){
            nParent.setLeft(theNode); theNodeParent.setRight(n);
        }else if( nParent.getRight() == n && theNodeParent.getLeft() == theNode ){
            nParent.setRight(theNode); theNodeParent.setLeft(n);
        }
        n.setParent( theNodeParent );
        theNode.setParent( nParent );
    }
    private Node getParentOfNode(String symbol){
        Node n = getNode(symbol);
        if(n == null) {
            if (nodesList.size() == 1) {
                return nodesList.get(0);
            } else {
                return nodesList.get(nodesList.size() - 2);     //the NYT node
            }
        }
        return n.getParent();
    }
    private Node getNode(String c){
        for(int i = 0; i < nodesList.size(); i++){
            if(nodesList.get(i).nodeSymbol.equals(c)) {
                return nodesList.get(i);
            }
        }
        return null;
    }
    private String Height(Node n){
        String res = "";
        while(n.getParent() != null) {
            String x = (n.getParent().getLeft() == n ? "0" : "1");
            res = x + res;
            n = n.getParent();
        }
        return res;
    }
    public String isCODE(String test){
        for (Node aNodesList : nodesList) {
            if (Height(aNodesList).equals(test) && !aNodesList.nodeSymbol.equals("NYT")) {
                return aNodesList.nodeSymbol;
            }
        }
        return null;
    }
}
