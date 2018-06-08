using System;

class MainClass
{
	public static void Main (string[] args)
	{
		RedBlackBST<int, int> bst = new RedBlackBST<int, int> (com);
		bst.Put (7, 7);
		bst.Put (6, 6);
		bst.Put (3, 3);
		bst.Put (5, 5);
		bst.Put (4, 4);
		bst.Print ();
		Console.WriteLine ( bst.Get (4) );

	}
	public static int com(int p, int q)
	{
		if (p > q)
			return 1;
		if (p < q)
			return -1;
		return 0;
	}


}
