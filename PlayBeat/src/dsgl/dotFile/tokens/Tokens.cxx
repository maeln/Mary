/*
 * Tokens.cxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#include "Tokens.hxx"

Tokens::Tokens(std::string value)
{
	m_value = value;
}

Tokens::~Tokens()
{
	// TODO Auto-generated destructor stub
}

std::string Tokens::get_value()
{
	return m_value;
}
