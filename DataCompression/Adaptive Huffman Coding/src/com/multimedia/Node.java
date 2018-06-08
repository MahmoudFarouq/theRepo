package com.multimedia;

class Node{

    public static final int NODE_NUMBER = 100;

    public String nodeSymbol;
    public int    nodeWight;

    private Node left;
    private Node right;
    private Node Parent;

    public Node getParent() {
        return Parent;
    }
    public void setParent(Node parent) {
        Parent = parent;
    }
    public Node getLeft() {
        return left;
    }
    public void setLeft(Node left) {
        this.left = left;
    }
    public Node getRight() {
        return right;
    }
    public void setRight(Node right) {
        this.right = right;
    }

    public Node(String ns, int weight){
        left = null; right = null;
        nodeSymbol = ns;
        nodeWight = weight;
    }

    /**
     * TO Swap:
     *  must be swappable, and the nodeNumber of (n) node
     *  must be less than the nodeNumber of (theNode) node
     */
    public boolean isSwappable(Node node) {
        if((nodeWight == node.nodeWight)
                && Parent != node
                && node.nodeWight != 0
                && getNodeNumber(this) < getNodeNumber(node)){
            return true;
        }
        return false;
    }

    private int getNodeNumber(Node n){
        int level = 0;
        Node temp = n;
        while(!temp.nodeSymbol.equals("rootNode") && level < NODE_NUMBER){
            level++;
            temp = temp.getParent();
        }
        if ( n.getParent().getLeft() == n ){
            return NODE_NUMBER - 2*level;
        }
        return NODE_NUMBER - 2*level + 1;
    }

    @Override
    public String toString(){
        return "Node{"+nodeSymbol+", "+nodeWight+"}";
    }
}