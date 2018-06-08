using System;

public class BHMaxPQ<T>
{
	public delegate bool Comparer(T p, T q);

	public Comparer Greater;
	T[] tree;
	int curIndex;
	public BHMaxPQ (int Capacity = 2)
	{
		tree = new T[Capacity];
		curIndex = 1;
	}
	public T delMax()
	{
		T max = tree [1];
		Exchange (1, --curIndex);
		Sink (1);
		return max;
	}
	private void Swim(int k)
	{
		while(k > 1 && Greater(tree[k], tree[k/2]))
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
			if (j < curIndex && !Greater (tree [j], tree [j+1])) {
				j++;
			}
			if (Greater (tree [k], tree [j])) {
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
		for(int i = 1; i < curIndex; i++)
		{
			Console.Write(tree[i] + " ");
		}
		Console.WriteLine ();
	}
}
