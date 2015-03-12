/*
 * Parser.cxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#include "Parser.hxx"

#include <iostream>

#include "../GraphException.hxx"
#include "ParsingException.hxx"

Parser::Parser()
{
}

Parser::~Parser()
{
}

Graph* Parser::parse(std::vector<Tokens> tokens)
{
	Graph* res = new Graph();
	for(unsigned int i = 0; i < tokens.size(); ++i)
		m_tokens.push(tokens[i]);

	parse_tokens(res);

	return res;
}

void Parser::parse_tokens(Graph* res)
{
	Tokens token = m_tokens.front();
	if(token.get_value() != "graph")
		throw ParsingException("File do not contain a graph.");

	m_tokens.pop();
	std::string graph_name = m_tokens.front().get_value();

	m_tokens.pop();
	token = m_tokens.front();
	if(token.get_value() != "{")
		throw ParsingException("Missing closing bracket.");

	m_tokens.pop();
	token = m_tokens.front();
	while(token.get_value() != "}" && !m_tokens.empty())
	{
		Node* n1 = NULL;
		std::string node = token.get_value();
		std::size_t found = node.find('\0');
		if (found!=std::string::npos)
			std::cout << "first '\\0' found at: " << found << '\n';

		n1 = res->add_node_by_name(node.c_str());

		m_tokens.pop();
		token = m_tokens.front();
		if(token.get_value() == "--")
		{
			m_tokens.pop();
			token = m_tokens.front();

			Node* n2 = NULL;
			std::string node2 = token.get_value();
			std::size_t found = node2.find('\0');
			if (found!=std::string::npos)
				std::cout << "first '\\0' found at: " << found << '\n';

			n2 = res->add_node_by_name(node2.c_str());

			if(n1 != NULL && n2 != NULL)
			{
				std::cout << "link: " << n1->get_name() << " | " << n1->get_name() << std::endl;
				res->link_nodes(n1, n2);
			}

			m_tokens.pop();
			token = m_tokens.front();
		}

	}
}
