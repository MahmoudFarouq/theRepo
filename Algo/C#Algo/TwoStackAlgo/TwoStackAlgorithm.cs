using System;

public class TwoStackAlgorithm
{
	Stack<string> values;
	Stack<string> operators;
	string[] splitedOperation;
	string _operation;
	string Operation{
		set{
			_operation = value;
			Split ();
		}
		get{
			return _operation;
		}
	}

	public TwoStackAlgorithm (string x)
	{
		values = new Stack<string> ();
		operators = new Stack<string> ();
		Operation = x;
	}
	private void Split()
	{
		splitedOperation = Operation.Split (' ');
	}
	public string CalculateValue()
	{
		foreach(string s in splitedOperation)
		{
			switch(s)
			{
				case "+": case "-": case "/":case "*":operators.Push (s);break;
				case "(":break;
				case ")":Calculate ();break;
				default:values.Push (s);break;
			}
		}
		Calculate ();
		Console.WriteLine ( (values.Pop ()) );
		Console.WriteLine ( (values.Pop ()) );
		return  ( values.Pop ());
	}
	private void Calculate()
	{
		if (values.Size () < 2 || operators.Size () < 1)
			return;
		float y = float.Parse (values.Pop ());
		float x = float.Parse (values.Pop ());
		float value = 0;
		char oper = char.Parse (operators.Pop ());
		switch(oper)
		{
			case '+':value = x + y;break;
			case '-':value = x - y;break;
			case '*':value = x * y;break;
			case '/':value = x / y;break;
		}
		values.Push ( value.ToString () );
	}
}

