using System;

//LIFO
//A5er wa7ed da5al howa awel wa7ed ye5rog
public class Stack<T>
{
	private class Node
	{
		public T item;
		public Node next;
	}
	Node stack;
	int curIndex = 0;
	public Stack ()
	{
		stack = new Node();
		stack.next = null;
	}
	public void Push(T item)		//INSERT an item into the stack
	{
		Node temp = new Node ();
		temp.item = item;
		temp.next = stack;
		stack = temp;
		curIndex++;
	}
	public T Pop()				//removes Item from stack
	{
		if (curIndex == 0)
			return default(T);
		T item = stack.item;
		stack = stack.next;
		curIndex--;
		System.GC.Collect ();
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
		Node it = stack;
		while(it != null)
		{
			Console.WriteLine ( it.item );
			it = it.next;
		}
	}
}

