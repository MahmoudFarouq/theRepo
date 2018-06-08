using System;

class MainClass
{
	public static void Main (string[] args)
	{
		while(true)
		{
			Console.Write ("calc> ");
			string x = Console.ReadLine ();
			try{
				Lexer lex = new Lexer (x);
				Interpreter intprt = new Interpreter(lex);
				Console.WriteLine ( intprt.Parse () );
			}catch(Exception c){
				Console.WriteLine ( c.Message );
			}
		}
	}
}
