using System;

//Double Ended Queue
public class Deque<T>
{
	private class Node
	{
		public T item;
		public Node right;
		public Node left;
	}

	Node last;
	Node start;
	int curIndex = 0;

	public Deque ()
	{
		start = new Node();
		start.left = null;
		start.right = null;
		last = start;
	}
	public void pushLeft(T item)		//INSERT an item into the stack
	{
		Node temp = new Node ();
		temp.item = item;
		start.left = temp;
		temp.right = start;
		start = temp;
		if (curIndex == 0) {
			start = temp;
			last = temp;
		}
		curIndex++;
	}
	public void pushRight(T item)		//INSERT an item into the stack
	{
		Node temp = new Node ();
		temp.item = item;
		last.right = temp;
		temp.left = last;
		last = temp;
		if (curIndex == 0)
			start = temp;
			last = temp;
		curIndex++;
	}
	public T popLeft()				//removes Item from stack
	{
		T item = start.item;
		start = start.right;
		curIndex--;
		return item;
	}
	public T popRight()				//removes Item from stack
	{
		T item = last.item;
		last = last.left;
		last.right = null;
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
			it = it.right;
		}
	}
}

