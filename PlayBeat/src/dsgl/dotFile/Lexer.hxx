/*
 * Lexer.hxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#ifndef DSGL_DOTFILE_LEXER_HXX_
#define DSGL_DOTFILE_LEXER_HXX_

#include <vector>
#include <string>
#include <fstream>

#include "tokens/Tokens.hxx"

class Lexer
{
	public:
		Lexer();
		virtual ~Lexer();

		std::vector<Tokens> get_all_tokens(std::ifstream& stream);
		Tokens get_token(std::ifstream& stream);
};

#endif /* DSGL_DOTFILE_LEXER_HXX_ */
