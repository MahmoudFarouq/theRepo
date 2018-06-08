using System;

public enum TYPE{INTEGER, PLUS, MINUS, MULT, DIVI, LPARE, RPARE, EOF};

public class Token
{
	public string value;
	public TYPE type;

	public Token(TYPE t, string v)
	{
		value = v;
		type = t;
	}
	//override the string representation for Console.WriteLine ();
	public override string ToString ()
	{
		return String.Format("Token({0}, {1})", type, value);
	}

}
