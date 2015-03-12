/*
 * Parser.hxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#ifndef DSGL_DOTFILE_PARSER_HXX_
#define DSGL_DOTFILE_PARSER_HXX_

#include <vector>
#include <string>
#include <queue>
#include "tokens/Tokens.hxx"
#include "../Graph.hxx"
#include "../Node.hxx"

class Parser
{
	public:
		Parser();
		virtual ~Parser();

		Graph* parse(std::vector<Tokens> tokens);
		void parse_tokens(Graph* res);

	private:
		std::queue<Tokens> m_tokens;
};

#endif /* DSGL_DOTFILE_PARSER_HXX_ */
