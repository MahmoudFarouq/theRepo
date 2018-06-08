using System;
using System.Collections.Generic;

//Abstract Syntax Tree
public class AST
{
	public AST ()
	{
	}
}
class BinOp : AST
{
	public Token oper;
	public AST left;
	public AST right;
	public BinOp (AST l, Token op, AST r)
	{
		left = l; right = r; oper = op;
	}
}
class UnaryOp : AST
{
	public Token oper;
	public AST right;
	public UnaryOp (Token op, AST r)
	{
		right = r; oper = op;
	}
}
class Num : AST
{
	public Token token;
	string value;
	public Num (Token tok)
	{
		token = tok;
		value = tok.value;
	}
}
class Compound : AST
{
	public List<AST> children;
	public Compound(){
		children = new List<AST> ();
	}
}
class Assign : AST
{
	public Var left;
	public Token oper;
	public AST right;
	public Assign(Var l, Token op, AST r)
	{
		left = l; right = r; oper = op;
	}
}
class Var : AST
{
	public Token token;
	public string value;
	public Var(Token tok)
	{
		token = tok;
		value = tok.value;
	}
}
class NoOp : AST
{
	
}
