using System;

//weightedUF
//faster but too slow
public class ImprovedQuickUF
{
	int[] items;
	int[] size;
	//O(n)
	public ImprovedQuickUF (int N)
	{
		items = new int[N];
		size = new int[N];
		for (int i = 0; i < N; i++) {
			items [i] = i;
			size [i] = 1;
		}
	}
	//chasing the root 
	private int root(int i)
	{
		while (i != items [i]) {
			//makes the tree almost flat, better than finding the root and go
			//all the way up every time, it's done
			items [i] = items [items [i]];
			i = items [i];
		}
		return i;
	}
	//lg(n)
	public void Union(int p, int q)
	{
		int i = root (p);
		int j = root (q);
		if (i == j)
			return;
		//find the maximum tree size and add the minimum to it, making a small trees
		if(size[i] > size[j])
			{items [i] = j;size [j] += size [i];}
		else
			{items [j] = i; size [i] += size [j];}
	}
	//lg(n)
	public bool Connected(int p, int q)
	{
		return root(p) == root(q);
	}
}
