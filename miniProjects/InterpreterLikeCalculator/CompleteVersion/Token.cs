using System;

public enum TYPE{INTEGER, PLUS, MINUS, MULT, DIVI, LPARE, RPARE, EOF, BEGIN, END, ID, ASSIGN, SEMI, DOT};

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


/*
NEW Semi-Complete Grammer(part 9)

program : compound_statement DOT

    compound_statement : BEGIN statement_list END

    statement_list : statement
                   | statement SEMI statement_list

    statement : compound_statement
              | assignment_statement
              | empty

    assignment_statement : variable ASSIGN expr

    empty :

    expr: term ((PLUS | MINUS) term)*

    term: factor ((MUL | DIV) factor)*

    factor : PLUS factor
           | MINUS factor
           | INTEGER
           | LPAREN expr RPAREN
           | variable

    variable: ID
*/




