using System;
using System.Collections.Generic;

public class Parser
{
	Lexer lexer;
	Token curToken;
	public Parser (Lexer lex)
	{
		lexer = lex;
		curToken = lex.getNextToken ();
	}
	public void error(string err){
		throw new Exception("Error parsing input: " + err);
	}
	public bool EatToken(TYPE tokenType)
	{
		/*compare the current token type with the passed token
			 type and if they match then "eat" the current token
			 and assign the next token to the current_token,
			 otherwise raise an exception.*/
		if (curToken.type == tokenType) {
			curToken = lexer.getNextToken ();
			return true;
		} else {
			error ("Wrong Token Thrown: " + tokenType );
		}
		return false;
	}
	AST Program()
	{
		//"""program : compound_statement DOT"""
		AST node = CompoundStatement ();
		//EatToken (TYPE.DOT);
		return node;
	}
	AST CompoundStatement()
	{
		//"""compound_statement: BEGIN statement_list END"""
		//EatToken (TYPE.BEGIN);
		List<AST> nodes = StatementList ();
		//EatToken (TYPE.END);
		Compound root = new Compound ();
		foreach (AST node in nodes)
			root.children.Add (node);
		return root;
	}
	List<AST> StatementList()
	{
		//"""statement_list : statement | statement SEMI statement_list"""
		AST node = Statement ();
		List<AST> result = new List<AST>{ node };

		while(curToken.type == TYPE.SEMI){
			EatToken (TYPE.SEMI);
			result.Add (Statement());
		}
		if(curToken.type == TYPE.ID){
			error ("fe 7aga 8alat");
		}
		return result;
	}
	AST Statement()
	{
		//"""statement : compound_statement | assignment_statement | empty"""
		AST node;
		if (curToken.type == TYPE.BEGIN)
			node = CompoundStatement ();
		else if (curToken.type == TYPE.ID)
			node = AssignmentStatement ();
		else 
			node = Expr ();
		return node;
	}
	AST AssignmentStatement()
	{
		//"""assignment_statement : variable ASSIGN expr"""
		Var left = Variable ();
		Token token = curToken;
		if(curToken.type == TYPE.ASSIGN)
			EatToken (TYPE.ASSIGN);
		else
			Console.WriteLine ( "Enta3abetYabni!" );
		AST right = Expr ();
		AST node  = new Assign (left, token, right);
		return node;
	}
	Var Variable()
	{
		Var node = new Var (curToken);
		EatToken (TYPE.ID);
		return node;
	}
	AST Empty()
	{
		return new NoOp ();
	}
	public AST Expr()
	{
		AST result = Term ();
		while(curToken.type == TYPE.PLUS || curToken.type == TYPE.MINUS)
		{
			Token token = curToken;
			if (token.type == TYPE.PLUS) {
				EatToken (TYPE.PLUS);
			} else if (token.type == TYPE.MINUS) {
				EatToken (TYPE.MINUS);
			}
			result = new BinOp (result, token, Term ());
		}
		return result;
	}
	public AST Term()
	{
		//"""term : factor ((MUL | DIV) factor)*"""
		AST result = Factor();
		while (curToken.type == TYPE.DIVI || curToken.type == TYPE.MULT)
		{
			Token token = curToken;
			if (curToken.type == TYPE.MULT) {
				EatToken (TYPE.MULT);
			} else if (curToken.type == TYPE.DIVI) {
				EatToken (TYPE.DIVI);
			}
			result = new BinOp (result, token, Factor ());
		}
		return result;
	}
	public AST Factor()
	{
		Token token = curToken;
		//for unary plus eg(+3)
		if(curToken.type == TYPE.PLUS){
			EatToken (TYPE.PLUS);
			return new UnaryOp (token, Factor ());	//return Term();
		}
		//for unary minus eg(-3)
		else if(curToken.type == TYPE.MINUS){
			EatToken (TYPE.MINUS);
			return new UnaryOp (token, Factor ()); //return new BinOp (new Num(new Token (TYPE.INTEGER, "-1")), new Token (TYPE.MULT, "*"), Term());
		}
		//for integers
		else if(curToken.type == TYPE.INTEGER){
			EatToken (TYPE.INTEGER);
			return new Num(token);
		}
		//for left and right parenthes eg(())
		else if (token.type == TYPE.LPARE) {
			EatToken (TYPE.LPARE);
			AST res = Expr ();
			EatToken (TYPE.RPARE);
			return res;
		}
		else if(token.type == TYPE.ID){
			return Variable ();
		}
		return new AST();
	}
	public AST Parse()
	{
		AST node = Program ();
		return node;
	}
}