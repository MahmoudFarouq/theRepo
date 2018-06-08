import java.util.List;


public abstract class Graph {
	
	private int numVertices;
	private int numEdges;
	
	public Graph(){
		setNumVertices(0);
		setNumEdges(0);
	}

	public void addVertex(){
		implementAddVertex();
		setNumVertices(getNumVertices() + 1);
	}
	
	public abstract void implementAddVertex();
	
	public abstract int[] getNeighbour(int v);

	public abstract void implementAddEdge(int v, int w);
	
	public int getNumVertices() {
		return numVertices;
	}

	public void setNumVertices(int numVertices) {
		this.numVertices = numVertices;
	}

	public int getNumEdges() {
		return numEdges;
	}

	public void setNumEdges(int numEdges) {
		this.numEdges = numEdges;
	}
	
	
}
