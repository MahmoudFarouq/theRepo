using System;

//FE hash table algorithm tany esmo linear probing enta 3arfo kasselt tektebo 34an enta 3el2
public class HashTable<Key, Value>
{
	public class Node
	{
		public Node(Key k, Value v, Node nex){key = k; value = v; next = nex;}
		public Key key;
		public Value value;
		public Node next;
	}

	public delegate int Hash(Key key);
	public delegate bool Comparer(Key k1, Key k2);

	private Hash hash;
	private Comparer IsEqualTo;
	private int MaxSize = 0;
	private Node[] table;
	public HashTable ( Hash hash, Comparer com, int s)
	{
		MaxSize = s;
		this.hash = hash;
		table = new Node[s];
		IsEqualTo = com;
	}
	public int MyHashCode(Key k)
	{						
		return Math.Abs ((hash(k) & 0x7fffffff) % MaxSize);
	}
	private Node Get(Key key)
	{
		int h = MyHashCode (key);
		Node p = table[h];
		while(p != null)
		{
			if (IsEqualTo(p.key, key))
				return p;
			p = p.next;
		}
		return null;
	}
	private void Put (Key k, Value v)
	{
		int h = MyHashCode (k);
		Node p = table[h];
		if (table [h] == null) {
			table [h] = new Node (k, v, null);
			return;
		}
		while(p != null)
		{
			if (IsEqualTo (p.key, k)) {
				p.value = v;
				return;
			}
			if (p.next == null)
				break;
			p = p.next;
		}
		p.next = new Node (k, v, null);
	}
	public Value this[Key key]
	{
		get
		{
			try{
				return Get(key).value;
			}catch(Exception ex)
			{
				Console.Write(ex.Message);
				return default(Value);
			}

		}
		set
		{
			Put (key, value);
		}
	}

}
