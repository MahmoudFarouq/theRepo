using System;
using System.Collections.Generic;

public class Interpreter
{
	public Parser parser;
	public Dictionary<string, string> GLOBAL_SCOPE;
	public Interpreter ()
	{
		GLOBAL_SCOPE = new Dictionary<string, string> ();
	}
	public string Interpret(){
		return Interpret ( parser.Parse () );
	}
	string Interpret(AST ast)
	{
		if (ast == null)								//if Null
			return "";
		else if (ast.GetType () == typeof(Num))			// if Number
			return Eval_Integer ((Num)ast);
		else if (ast.GetType () == typeof(UnaryOp))		//if Unary Operator
			return Eval_UnaryOp ((UnaryOp)ast);
		else if (ast.GetType () == typeof(BinOp)) 		// if Binary Operator
			return Eval_BinOp ((BinOp)ast);
		else if (ast.GetType () == typeof(Assign)) 		// if Assignment Operator
			Eval_Assign ((Assign)ast);
		else if (ast.GetType () == typeof(Compound)) 	// if Compound Statement
			Eval_Compound ((Compound)ast);
		else if(ast.GetType () == typeof(Var)) 			// if Variables
			return Eval_Var ((Var)ast);
		else if(ast.GetType () == typeof(NoOp)) 		// if NoOp
			Eval_NoOp ((NoOp)ast);
		return "";
	}
	string Eval_Integer(Num node){
		return node.token.value;	
	}
	string Eval_BinOp(BinOp node){
		switch(node.oper.type)
		{
			case TYPE.PLUS:
			return (int.Parse (Interpret (node.left)) + int.Parse (Interpret (node.right))).ToString ();
			case TYPE.MULT:
			return (int.Parse (Interpret (node.left)) * int.Parse (Interpret (node.right))).ToString ();
			case TYPE.DIVI:
			return (int.Parse (Interpret (node.left)) / int.Parse (Interpret (node.right))).ToString ();
			case TYPE.MINUS:
			return (int.Parse (Interpret (node.left)) - int.Parse (Interpret (node.right))).ToString ();
		}
		return "";
	}
	string Eval_UnaryOp(UnaryOp node){
		switch(node.oper.type)
		{
			case TYPE.PLUS:
			return Interpret (node.right);
			case TYPE.MINUS:
			return (-1*int.Parse (Interpret (node.right))).ToString ();
		}
		return "";
	}
	void Eval_Compound(Compound node)
	{
		if(node.children[0].GetType () == typeof(BinOp) && node.children.Count == 1){
			Console.Write (Interpret(node.children[0]));
		}else
		foreach (AST child in node.children)
			Interpret (child);
	}
	void Eval_NoOp(NoOp node)
	{
		return ;
	}
	void Eval_Assign(Assign node)
	{
		string varName = node.left.value;
		GLOBAL_SCOPE [varName] = Interpret (node.right);
	}
	string Eval_Var(Var node)
	{
		string varName = node.value;
		if (GLOBAL_SCOPE.ContainsKey (varName))
			return GLOBAL_SCOPE [varName];
		throw(new Exception ("Undefined Variable name"));
	}
}

/*
*  recursive-descent parsers
* 
*  a recursive-descent parser is a top-down parser that
*  uses a set of recursive procedures to process the input.
*  Top-down reflects the fact that the parser begins by
*  constructing the top node of the parse tree and then 
*  gradually constructs lower nodes.
*/