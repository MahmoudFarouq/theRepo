using System;

public class Interpreter
{
	Lexer lexer;
	Token curToken;
	public Interpreter (Lexer lex)
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
			error ("Wrong Token Thrown");
		}
		return false;
	}
	public string Factor()
	{
		Token token = curToken;
		if(curToken.type == TYPE.INTEGER){
			EatToken (TYPE.INTEGER);
			return token.value;
		}
		else if (token.type == TYPE.LPARE) {
			EatToken (TYPE.LPARE);
			string res = Parse ().ToString ();
			EatToken (TYPE.RPARE);
			return res;
		}
		return "0";
	}
	public string Term()
	{
		//"""term : factor ((MUL | DIV) factor)*"""
		string result = Factor();
		while (curToken.type == TYPE.DIVI || curToken.type == TYPE.MULT)
		{
			if (curToken.type == TYPE.MULT) {
				EatToken (TYPE.MULT);
				result = (int.Parse (result) * int.Parse (Factor ())).ToString ();
			} else if (curToken.type == TYPE.DIVI) {
				EatToken (TYPE.DIVI);
				result = (int.Parse (result) / int.Parse (Factor ())).ToString ();
			}
		}
		return result;
	}
	public int Parse()
	{
		string result = Term ();
		while(curToken.type == TYPE.PLUS || curToken.type == TYPE.MINUS)
		{
			Token token = curToken;
			if (token.type == TYPE.PLUS) {
				EatToken (TYPE.PLUS);
				result = (int.Parse (result) + int.Parse (Term ())).ToString ();
			} else if (token.type == TYPE.MINUS) {
				EatToken (TYPE.MINUS);
				result = (int.Parse (result) - int.Parse (Term ())).ToString ();
			}
		}
		return int.Parse (result);
	}
}