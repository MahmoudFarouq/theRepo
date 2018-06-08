import java.util.*;


public class GraphAdjList extends Graph{

	public class Node{
		private int v;
		private Node next;
		public Node(int val){
			setV(val);
			setNext(null);
		}
		public Node getNext() {
			return next;
		}
		public void setNext(Node next) {
			this.next = next;
		}
		public int getV() {
			return v;
		}
		public void setV(int v) {
			this.v = v;
		}
	}
	
	
	private Map<Integer, ArrayList<Integer>> adjList;
	
	public GraphAdjList(){
		adjList = new TreeMap<Integer, ArrayList<Integer>>();
	}
	
	@Override
	public void implementAddVertex() {
		int v = getNumVertices();
		adjList.put(v, new ArrayList<Integer>());
	}

	@Override
	public int[] getNeighbour(int v) {
		return null;
	}
	
	public void implementAddEdge(int v, int w){
		adjList.get(v).add(w);	
	}
}
