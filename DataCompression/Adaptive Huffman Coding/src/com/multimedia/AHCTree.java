package com.multimedia;
import java.util.Hashtable;
import java.util.LinkedList;

public class AHCTree {
    private LinkedList<Node> nodesList;
    private Hashtable<String, String> Dict;

    public AHCTree(){
        nodesList = new LinkedList<>();
        Dict      = new Hashtable<>();

        Dict.put("A", "00");
        Dict.put("B", "01");
        Dict.put("C", "10");

        nodesList.add(new Node("rootNode", 0));   //the root
        nodesList.get(0).setParent(null);
    }

    public String addNode(String nodeSymbol){
        String res = "";
        Node theParent = getParentOfNode(nodeSymbol);

        if( theParent.nodeWight == 0 ){      // first occurrence, the parent is a NYT node
            addNewNode(theParent, nodeSymbol);
            res += Height(theParent) + " ";       // the last NYT node
            res += Dict.get(nodeSymbol) + " ";    // the code in dict
        }else{         // old node
            res += Height(getNode(nodeSymbol)) + " ";
        }
        Node theNode = getNode(nodeSymbol);
        while(theNode != nodesList.get(0)){     // while thenode != root
            for( int i = 1; i < nodesList.size(); i++ ){
                Node n = nodesList.get(i);

                if( theNode.isSwappable(n)){
                    swap(theNode, n);
                    break;
                }
            }
            theNode.nodeWight++;
            theNode = theNode.getParent();
        }
        theNode.nodeWight++;
        return res;
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

    public boolean isNYT(String test){
        if( nodesList.size() < 3 ){
            return false;
        }
        String NYT = Height(nodesList.get(nodesList.size()-2));
        if(NYT.equals(test)){
            return true;
        }
        return false;
    }
    public String isCODEfromTree(String test){
        for (Node aNodesList : nodesList) {
            if (Height(aNodesList).equals(test) && !aNodesList.nodeSymbol.equals("NYT")) {
                return aNodesList.nodeSymbol;
            }
        }
        return null;
    }
    public String isCODEfromDict(String test){
        for(String key : Dict.keySet()){
            if( Dict.get(key).equals(test) ){
                return key;
            }
        }
        return null;
    }
}
