using System;

class MainClass
{
	public static void Main (string[] args)
	{
		ImprovedQuickUF uf = new ImprovedQuickUF (100);
		uf.Union(5,6);
		uf.Union(1,5);
		Console.WriteLine(uf.Connected(1, 6));
	}
}
