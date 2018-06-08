
public class GraphAdjMatrix extends Graph{

	private int[][] adjMatrix;
	
	public GraphAdjMatrix(){
		adjMatrix = new int[10][10];
	}
	
	@Override
	public void implementAddVertex() {
		int v = getNumVertices();
		if(v >= adjMatrix.length){
			extendMatrix();
		}
		for(int i = 0; i < adjMatrix[v].length; i++){
			adjMatrix[v][i] = 0;
		}
	}

	@Override
	public int[] getNeighbour(int v) {
		return adjMatrix[v];
	}
	
	public void implementAddEdge(int v, int w){
		adjMatrix[v][w] = 1;
	}
	
	public void extendMatrix(){
		int v = getNumVertices();
		int[][] newMatrix = new int[v*2][v*2];
		
		for(int i = 0; i < v; i++){
			for(int j = 0; j < v; j++){
				newMatrix[i][j] = adjMatrix[i][j];
			}
		}
		adjMatrix = newMatrix;
	}

}
