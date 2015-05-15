/*
 * StringFormat.cxx
 *
 *  Created on: 13 mars 2015
 *      Author: maeln
 */

#include "StringFormat.hxx"

#include <algorithm>
#include <sstream>

#include <iostream>

std::string StringFormat::to_plain_ascii(std::string str)
{
	std::stringstream ss;
	for(unsigned int i=0; i<str.size(); ++i)
	{
		char a = str[i];
		if(a > 31 && 127 > a)
			ss << str[i];
	}
	return ss.str();
}

std::string StringFormat::strip_whitespace(std::string str)
{
	std::stringstream ss;
		for(unsigned int i=0; i<str.size(); ++i)
			if(str[i] != 32)
				ss << str[i];
		return ss.str();
}

std::string StringFormat::to_downcase(std::string str)
{
	std::string res(str);
	std::transform(res.begin(), res.end(), res.begin(), ::tolower);
	return res;
}

std::string StringFormat::clean_all(std::string str)
{
	std::string res(to_plain_ascii(str));
	res = to_downcase(res);
	res = strip_whitespace(res);
	return res;
}
