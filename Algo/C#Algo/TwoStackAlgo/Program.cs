using System;

class MainClass
{
	public static void Main (string[] args)
	{
		Stack<string> operators = new Stack<string> ();
		Stack<string> result = new Stack<string> ();

		string input = "1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )";
		string[] split = input.Split (' ');

		foreach(var sym in split)
		{
			switch (sym)
			{
			case "+":
			case "-":
			case "*":
			case "/":
				operators.Push (sym);
				break;
			case ")":

				string y = result.Pop ();
				string x = result.Pop ();
				string c = operators.Pop ();
				string temp = "( " + x + " " + c + " " + y + " )";
				result.Push (temp);
				break;
			default:
				result.Push (sym);
				break;
			}
		}
		string res = result.Pop ();
		Console.WriteLine ( res );
	}

}