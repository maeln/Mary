/*
 * Tokens.hxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#ifndef DSGL_DOTFILE_TOKENS_TOKENS_HX_
#define DSGL_DOTFILE_TOKENS_TOKENS_HX_

#include <string>

class Tokens
{
	public:
		Tokens(std::string value);
		virtual ~Tokens();

		std::string get_value();

	private:
		std::string m_value;
};

#endif /* DSGL_DOTFILE_TOKENS_TOKENS_HX_ */
