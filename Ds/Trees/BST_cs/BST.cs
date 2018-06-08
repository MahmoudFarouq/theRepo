using System;
using System.Collections.Generic;
using System.Collections;

//Binary Search Tree
public class BST<Key, Value> : IEnumerable
{
	public class Node
	{
		public Node(Key key, Value value){this.key = key;this.value = value;}
		public Node(){}
		public Key key;
		public Value value;
		public Node left;
		public Node right;
	}
	public delegate int Comparer(Key k1, Key k2);

	private Comparer compare;
	public Node root;

	public BST (Comparer com)
	{
		compare = com;
	}

	public void Put(Key k, Value v)		
	{
		root = Put (root, k, v);
	}
	public Node Put(Node node, Key k, Value v)	
	{
		if (node == null)
			return new Node (k, v);
		int com = compare (k, node.key);
		if (com > 0)
			node.right = Put (node.right, k, v);
		else if (com < 0)
			node.left = Put (node.left, k, v);
		else
			node.value = v;
		return node;
	}

	public Value Get(Key k)	
	{
		Node temp = root;
		while(temp != null)
		{
			if(compare(k, temp.key) > 0)
				temp = temp.right;
			else if(compare(k, temp.key) < 0)
				temp = temp.left;
			else
				return temp.value;
		}
		return default(Value);
	}

	public void Print()
	{
		Print_DepthFirst (root);
	}
	public void Print_DepthFirst(Node n)
	{
		if (n != null) {
			Print_DepthFirst (n.left);
			Console.WriteLine (n.key + " => " + n.value);
			Print_DepthFirst (n.right);
		}
	}
	public void Print_BreadthFirst(Node n)
	{
		int t = 1;
		int c = 1;
		Queue<Node> q = new Queue<Node> ();
		q.Enqueue (n);
		Node temp;
		while(q.Count != 0)
		{

			temp = q.Dequeue ();
			if(temp != null)
			{
				q.Enqueue (temp.left);
				q.Enqueue (temp.right);
				Console.Write (temp.value);
			}
			if(t == c)
			{
				Console.WriteLine ();
				c *= 2;
				t = 0;
			}
			t++;
		}
		Console.WriteLine ();
	}

	public Node min()
	{
		return min(root);
	}
	private Node min(Node x)
	{
		if (x.left == null) return x;
		return min(x.left);
	}

	public Key floor(Key key)
	{
		Node x = floor(root, key);
		if (x == null) return default(Key);
		return x.key;
	}
	private Node floor(Node x, Key key)
	{
		if (x == null) return null;
		int cmp = compare(key, x.key);
		if (cmp == 0) return x;
		if (cmp < 0) return floor(x.left, key);
		Node t = floor(x.right, key);
		if (t != null) return t;
		else return x;
	}
		
	public void DeleteMin()
	{
		root = DeleteMin (root);
	}
	private Node DeleteMin(Node node)
	{
		if (node.left != null)
			node.left = DeleteMin (node.left);
		else
			return node.right;
		return node;
	}

	public void DeleteMax()
	{
		root = DeleteMax (root);
	}
	public Node DeleteMax(Node node)
	{
		if (node.right == null)
			return node.left;
		else
			node.right = DeleteMax (node.right);
		return node;
	}

	public void delete(Key key)
	{ 
		root = another_delete(root, key); 
	}
	private Node delete(Node node, Key key)
	{
		if (node == null)
			return null;
		int cmp = compare (node.key, key);
		if (cmp > 0)
			node.left = delete (node.left, key);		//go left
		else if (cmp < 0)
			node.right = delete (node.right, key);	//go right
		else 									//found node to delete
		{
			if (node.right == null)
				return node.left;
			if (node.left == null)
				return node.right;
			
			Node temp = node;
			node = min (temp.right);
			node.right = DeleteMin (temp.right);
			node.left = temp.left;

		}
		return node;
	}
	private Node another_delete(Node node, Key key)
	{
		if (node == null)
			return null;
		int cmp = compare (node.key, key);
		if (cmp > 0)
			node.left = delete (node.left, key);		//go left
		else if (cmp < 0)
			node.right = delete (node.right, key);	//go right
		else 									//found node to delete
		{
			if (node.right == null)
				return node.left;
			if (node.left == null)
				return node.right;

			Node temp = min (node.right);
			node.key = temp.key;
			node.value = temp.value;
			node.right = DeleteMin (node.right);
		}
		return node;
	}

	public IEnumerator GetEnumerator()
	{
		Queue<Key> q = new Queue<Key> ();
		PutInQueue (root, q);
		return q.GetEnumerator ();
	}
	private void PutInQueue(Node n, Queue<Key> q)
	{
		if (n != null) {
			PutInQueue (n.left, q);
			q.Enqueue (n.key);
			PutInQueue (n.right, q);
		}
	}
}