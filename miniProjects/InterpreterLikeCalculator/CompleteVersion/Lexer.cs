using System;
using System.Collections.Generic;

public class Lexer
{
	string expression;
	int pos;
	Dictionary<string, Token> RESERVED_KEYWORDS;
	public Lexer (string text)
	{
		RESERVED_KEYWORDS = new Dictionary<string, Token> (){
			{"BEGIN", new Token(TYPE.BEGIN, "BEGIN")},
			{"END", new Token(TYPE.END, "END")}
		};
		expression = text;
		pos = 0;
	}
	public void error(string err){
		throw new Exception("Error parsing input: " + err);
	}
	public Token getNextToken()	//Lexical analyzer (also known as scanner or tokenizer)
	{
		if (pos >= expression.Length) return new Token(TYPE.EOF, null);
		char curChar = expression [pos];
		if (curChar == ' ') skipWhiteSpace (ref curChar);
		if(char.IsLetter (curChar)){return _id ();}
		if ( char.IsDigit (curChar) ) {return IntegerNum ();}
		if(curChar == '='){pos++; return new Token (TYPE.ASSIGN, "=");}
		if(curChar == ';'){pos++; return new Token (TYPE.SEMI, ";");}
		if(curChar == '.'){pos++; return new Token (TYPE.DOT, ".");}
		if(curChar == '+'){pos++; return new Token (TYPE.PLUS, "+");}
		if(curChar == '-'){pos++; return new Token (TYPE.MINUS, "-");}
		if(curChar == '*'){pos++; return new Token (TYPE.MULT, "*");}
		if(curChar == '/'){pos++; return new Token (TYPE.DIVI, "/");}
		if(curChar == '('){pos++; return new Token (TYPE.LPARE, "(");}
		if(curChar == ')'){pos++; return new Token (TYPE.RPARE, ")");}
		error ("Wrong Token Type");
		return new Token (TYPE.EOF, null);
	}
	char Peek(){
		int peek_pos = pos + 1;
		if(peek_pos >= expression.Length)
			return default(char);
		return expression[peek_pos];
	}
	Token _id(){
		//"""Handle identifiers and reserved keywords"""
		string result = "";
		while( pos < expression.Length &&  char.IsLetterOrDigit (expression[pos])){
			result += expression[pos];
			pos++;
		}
		if(RESERVED_KEYWORDS.ContainsKey (result)){
			return RESERVED_KEYWORDS [result];
		}
		return new Token (TYPE.ID, result);
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