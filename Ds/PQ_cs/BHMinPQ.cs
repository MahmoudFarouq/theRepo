using System;

public class BHMinPQ<T>
{
	public delegate bool Greater(T p, T q);

	public Greater Less;
	T[] tree;
	int curIndex;
	public BHMinPQ (int Capacity = 2)
	{
		tree = new T[Capacity];
		curIndex = 1;
	}
	public T delMin()
	{
		T min = tree [1];
		Exchange (1, --curIndex);
		Sink (1);
		return min;
	}
	private void Swim(int k)
	{
		while(k > 1 && !Less(tree[k], tree[k/2]))
		{
			Exchange (k, k / 2);
			k /= 2;
		}
	}
	private void Sink(int k)
	{
		while(k*2 < curIndex-1)
		{
			int j = 2 * k;
			if (j < curIndex && Less (tree [j], tree [j+1])) {
				j++;
			}
			if (!Less (tree [k], tree [j])) {
				break;
			}
			Exchange (k, j);
			k = j;
		}
	}
	private void Exchange(int k, int k2)
	{
		T temp = tree [k];
		tree [k] = tree [k2];
		tree [k2] = temp;
	}
	public void Insert(T item)
	{
		if (curIndex > tree.Length-1)
			MaximizeTree ();
		tree [curIndex++] = item;
		Swim (curIndex-1);
	}
	public void MaximizeTree()
	{
		int len = tree.Length;
		T[] temp = new T[len * 2];
		for(int i = 0; i < len; i++)
		{
			temp [i] = tree [i];
		}
		tree = temp;
	}
	public void print()
	{
		//using breadth first on array
		int t = 1;
		for(int i = 1; i < curIndex; i++)
		{
			Console.Write(tree[i] + " ");
			if(i == t)
			{
				Console.WriteLine ();
				t *= 2;
			}
		}
		Console.WriteLine ();
	}
}

