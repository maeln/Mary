/*
 * Lexer.cxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#include "Lexer.hxx"

#include "ParsingException.hxx"

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}

std::vector<Tokens> Lexer::get_all_tokens(std::ifstream& stream)
{
	std::vector<Tokens> tokens;
	Tokens cur(" ");
	while(cur.get_value() != "\0")
	{
		cur = get_token(stream);
		tokens.push_back(cur);
	}

	return tokens;
}

Tokens Lexer::get_token(std::ifstream& stream)
{
	char c;
	std::string word("");
	while(stream.get(c))
	{
		if(c == ';')
			return Tokens(word);
		if(c == '}')
			return Tokens("}");
		if(c == '{')
			return Tokens("{");
		if(c == '-')
		{
			if(word.empty())
			{
				return Tokens("--");
			}
			else
			{
				return Tokens(word);
			}
		}
		if(c == ' ' || c == '\n' || c == '\r' || c == '\t')
		{
			if(!word.empty())
			{
				return Tokens(word);
			}
		}
		else
			word += c;
	}

	return Tokens("\0");
}
