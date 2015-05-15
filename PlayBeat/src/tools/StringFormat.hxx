/*
 * StringFormat.hxx
 *
 *  Created on: 13 mars 2015
 *      Author: maeln
 */

#ifndef TOOLS_STRINGFORMAT_HXX_
#define TOOLS_STRINGFORMAT_HXX_

#include <string>

class StringFormat
{
	public:
		std::string to_plain_ascii(std::string str);
		std::string strip_whitespace(std::string str);
		std::string to_downcase(std::string str);
		std::string clean_all(std::string str);
};

#endif /* TOOLS_STRINGFORMAT_HXX_ */
