using System;

public class Lexer
{
	string expression;
	int pos;
	public Lexer (string text)
	{
		expression = text;
		pos = 0;
	}
	public void error(string err){
		throw new Exception("Error parsing input: " + err);
	}
	/*This method is responsible for breaking a sentence
		apart into tokens. One token at a time.*/
	public Token getNextToken()	//Lexical analyzer (also known as scanner or tokenizer)
	{
		if (pos >= expression.Length)
			return new Token(TYPE.EOF, null);
		char curChar = expression [pos];
		if (curChar == ' ')
			skipWhiteSpace ( ref curChar );
		if (curChar >= '0' && curChar <= '9') {
			return IntegerNum ();
		}
		else if(curChar == '+'){
			pos++;
			return new Token (TYPE.PLUS, "+");
		}
		else if(curChar == '-'){
			pos++;
			return new Token (TYPE.MINUS, "-");
		}
		else if(curChar == '*'){
			pos++;
			return new Token (TYPE.MULT, "*");
		}else if(curChar == '/'){
			pos++;
			return new Token (TYPE.DIVI, "/");
		}else if(curChar == '('){
			pos++;
			return new Token (TYPE.LPARE, "(");
		}else if(curChar == ')'){
			pos++;
			return new Token (TYPE.RPARE, ")");
		}
		error ("Wrong Token Type");
		return new Token (TYPE.EOF, null);
	}
	void skipWhiteSpace(ref char curChar){
		while(curChar == ' '){
			curChar = expression [++pos];
		}
	}
	Token IntegerNum(){
		char curChar = expression [pos];
		Token res = new Token(TYPE.INTEGER, "");
		while (curChar >= '0' && curChar <= '9') {
			res.value += curChar;
			pos++;
			if (pos >= expression.Length)
				break;
			curChar = expression [pos];
			skipWhiteSpace (ref curChar);
		}
		return res;
	}
}

