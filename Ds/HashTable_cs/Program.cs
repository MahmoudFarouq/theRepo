using System;


class MainClass
{
	public static void Main (string[] args)
	{
		HashTable<string, string> ht = new HashTable<string, string> (Hash, IsEqual, 20);
		Console.WriteLine ( ht.MyHashCode ("AaAAA") );
		Console.WriteLine ( ht.MyHashCode ("BBAAA") );
	}

	//Horners Method for Strings
	public static int Hash(string x)
	{
		int hash = 0;
		for (int i = 0; i < x.Length; i++)
			hash = x [i] + (31 * hash);
		return hash;
	}

	public static bool IsEqual(string x, string y)
	{
		if (x.Length != y.Length)
			return false;
		for (int i = 0; i < x.Length; i++)
			if (x [i] != y [i])
				return false;
		return true;
	}
}