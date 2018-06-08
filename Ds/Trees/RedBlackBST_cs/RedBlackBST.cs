using System;

//left leaning red black tree
public class RedBlackBST<Key, Value>
{
	private static bool RED = true;
	private static bool BLACK = false;
	public delegate int Comparer(Key k1, Key k2);
	public class Node
	{
		public Node(Key key, Value value, bool color){this.key = key;this.value = value;this.color = color;}
		public Node(){}
		public Key key;
		public Value value;
		public Node left, right;
		public bool color;	//color of parent node
	}

	private Node root;
	private Comparer compare;
	public RedBlackBST (Comparer com)
	{
		compare = com;
	}
	private void FlipColor(Node h)
	{
		if (IsRed (h))
			return;
		if (!IsRed (h.right))
			return;
		if (!IsRed (h.left))
			return;
		h.color = RED;
		h.left.color = BLACK;
		h.right.color = BLACK;
	}
	private Node RotateLeft(Node h)
	{
		if (!IsRed (h.right))
			return h;
		Node x = h.right;
		h.right = x.right;
		x.left = h;
		x.color = h.color;
		h.color = RED;
		return x;
	}
	private Node RotateRight(Node h)
	{
		if (!IsRed (h.left))
			return h;
		Node x = h.left;
		h.left = x.right;
		x.right = h;
		x.color = h.color;
		h.color = RED;
		return x;
	}

	public bool Delete(Key k)
	{
		Node toDelete = GetForDelete (k);
		if (toDelete == null)
			return false;


		return true;

	}

	private bool IsRed(Node x)
	{
		if (x == null)
			return false;
		return x.color == RED;
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
	public Node GetForDelete(Key k)	
	{
		Node temp = root;
		while(temp != null)
		{
			if(compare(k, temp.key) > 0)
				temp = temp.right;
			else if(compare(k, temp.key) < 0)
				temp = temp.left;
			else
				return temp;
		}
		return null;
	}
	public void Put(Key k, Value v)		
	{
		root = Put (root, k, v);
	}
	private Node Put(Node h, Key k, Value v)
	{
		if (h == null) return new Node (k, v, RED);
		int cmp = compare (k, h.key);
		if (cmp > 0)
			h.right = Put (h.right, k, v);
		else if (cmp < 0)
			h.left = Put (h.left, k, v);
		else
			h.value = v;

		if (IsRed (h.right) && !IsRed (h.left))
			h = RotateLeft (h);
		if (IsRed (h.left) && IsRed (h.left.left))
			h = RotateRight (h);
		if (IsRed (h.left) && IsRed (h.right))
			FlipColor (h);
		return h;
	}
	public void Print()
	{
		Print (root);
	}
	public void Print(Node n)
	{
		if (n != null) {
			Print (n.left);
			Console.WriteLine (n.key + " => " + n.value);
			Print (n.right);
		}
	}
}