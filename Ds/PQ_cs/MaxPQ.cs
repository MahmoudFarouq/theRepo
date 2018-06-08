using System;

public delegate int Greater<T>(T p, T q);

public class MaxPQ<T>
{
	T[] queue;
	int curIndex = 0;
	public Greater<T> Greater;
	public MaxPQ ()
	{
		queue = new T[2];
	}
	public MaxPQ(T[] array)
	{
		queue = new T[array.Length];
		array.CopyTo (queue, 0);
		curIndex = array.Length;
	}
	public void Insert(T item)
	{
		if(curIndex > queue.Length-1) 
			MaximiseTheQueue();
		InsertionSort (item);
		curIndex++;
	}
	public T delMax()
	{
		if(curIndex >= 0)
			curIndex--;
		return queue[curIndex];
	}
	public bool isEmpty()
	{
		return curIndex == -1;
	}
	public T GetMax()
	{
		return queue [curIndex-1];
	}
	public int Size()
	{
		return curIndex;
	}
	public void Print()
	{
		for(int i = 0; i < curIndex; i++)
			Console.Write (	queue[i] + " " );
		Console.WriteLine ();
	}
	public void InsertionSort(T item)
	{
		int j = 0;
		if(!(curIndex == 0))
			for(j = curIndex; j > 0 ; j--)
			{
				if (Greater(queue [j-1], item) > 0) {
					queue [j] = queue [j - 1];
				} else
					break;
			}
		queue [j] = item;
	}
	public void MaximiseTheQueue()
	{
		int len = queue.Length;
		T[] temp = new T[len * 2];
		for(int i = 0; i < len-1; i++)
		{
			temp [i] = queue [i];
		}
		queue = temp;
	}
}