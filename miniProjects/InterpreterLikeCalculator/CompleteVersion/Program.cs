using System;
using System.Collections.Generic;

class MainClass
{
	public static void Main (string[] args)
	{
		Interpreter intepreter = new Interpreter();
		/*
			The parser gets tokens from the lexer
			and then returns the generated AST for the interpreter
			to traverse and interpret the input
		*/
		while(true)
		{
			Console.Write ("calc> ");
			string expression = "";
			string x = Console.ReadLine ();
			expression += x;
			try{
				Lexer lex = new Lexer (expression);
				Parser parser = new Parser(lex);
				intepreter.parser = parser;
				if( intepreter.GLOBAL_SCOPE.ContainsKey (expression) ){
					Console.WriteLine ( intepreter.GLOBAL_SCOPE[expression] );
				}else{
					Console.WriteLine ( intepreter.Interpret () );
				}
			}catch(Exception c){
				Console.WriteLine ( c.Message );
			}
		}
	}
}