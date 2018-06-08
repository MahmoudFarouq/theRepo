using System;

public class UnionFind
{
	int numberOfObjects;
	int[] items;
	//O(n)
	public UnionFind (int N)
	{
		numberOfObjects = N;
		items = new int[N];
		for (int i = 0; i < N; i++) {
			items [i] = i;
		}
	}
	//O(n)
	public void Union(int p, int q)
	{
		if (Connected (p, q))
			return;
		int temp = items [p];
		for(int i = 0; i < numberOfObjects; i++)
		{
			if(items[i] == temp)
			{
				items [i] = items [q];
			}
		}
		numberOfObjects--;
		for(int i = 0; i < numberOfObjects; i++)
		{
			Console.WriteLine ( i + " 's Root is " + items[i] );
		}
	}
	//O(1)
	public bool Connected(int p, int q)
	{
		return (items [p] == items [q]);
	}
}

