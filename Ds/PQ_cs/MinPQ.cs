using System;
using System.Collections;

public class MinPQ<T> : IEnumerable
{
	T[] queue;
	int curIndex = 0;
	public Greater<T> Greater;
	public MinPQ ()
	{
		queue = new T[1];
	}
	public MinPQ(T[] array)
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
	public T delMin()
	{
		if(curIndex > 0)
		{
			curIndex--;
			return queue[curIndex];
		}
		return default(T);
	}
	public bool isEmpty()
	{
		return curIndex == 0;
	}
	public T GetMin()
	{
		if (curIndex == 0)
			return default(T);
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
				if (Greater(queue [j-1], item) < 0) {
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
		queue.CopyTo (temp, 0);
		queue = temp;
	}

	public IEnumerator GetEnumerator()
	{
		return queue.GetEnumerator ();
	}
}