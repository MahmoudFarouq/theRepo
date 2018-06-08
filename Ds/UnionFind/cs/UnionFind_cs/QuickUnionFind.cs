using System;

//faster but too slow
public class QuickUnionFind
{
	int[] items;
	//O(n)
	public QuickUnionFind (int N)
	{
		items = new int[N];
		for (int i = 0; i < N; i++) {
			items [i] = i;
		}
	}
	//lg(n)
	//chasing the root 
	private int root(int i)
	{
		//while root != entry
		while (i != items [i])
			//go up
			i = items [i];
		return i;
	}
	//change the first's root to be the seconds root
	public void Union(int p, int q)
	{
		items [root (p)] = root (q);
	}
	//lg(n)
	public bool Connected(int p, int q)
	{
		return root(p) == root(q);
	}
}

