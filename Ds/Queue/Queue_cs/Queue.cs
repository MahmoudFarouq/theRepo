using System;

//FIFO
//AWEL wa7ed da5al howa awel wa7ed ye5rog
public class Queue<T>
{
	private class Node
	{
		public T item;
		public Node next;
	}

	Node last;
	Node start;
	int curIndex = 0;
	public Queue ()
	{
		start = new Node();
		start.next = null;
		last = start;
	}
	public void enQueue(T item)		//INSERT an item into the stack
	{
		Node temp = new Node ();
		temp.item = item;
		last.next = temp;
		last = temp;
		if (curIndex == 0)
			start = temp;
		curIndex++;
	}
	public T deQueue()				//removes Item from stack
	{
		T item = start.item;
		start = start.next;
		curIndex--;
		return item;
	}
	public bool isEmpty()
	{
		return curIndex == 0;
	}
	public int Size()
	{
		return curIndex;
	}
	public void Print()
	{
		Node it = start;
		while(it != null)
		{
			Console.WriteLine ( it.item );
			it = it.next;
		}
	}
}
