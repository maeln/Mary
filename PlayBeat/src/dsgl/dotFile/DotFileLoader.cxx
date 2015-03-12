/*
 * DotFileLoader.cxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#include "DotFileLoader.hxx"

#include <fstream>
#include <vector>

#include "../Graph.hxx"
#include "Lexer.hxx"
#include "Parser.hxx"
#include "ParsingException.hxx"

DotFileLoader::DotFileLoader()
{

}

DotFileLoader::~DotFileLoader()
{

}

Graph* DotFileLoader::load(std::string file)
{
	Lexer lex;
	Parser pars;
	Graph* res;

	std::ifstream dotFile(file.c_str(), std::ifstream::in);
	if(!dotFile)
		throw ParsingException("Cannot open file.");

	res = pars.parse(lex.get_all_tokens(dotFile));
	dotFile.close();

	return res;
}
