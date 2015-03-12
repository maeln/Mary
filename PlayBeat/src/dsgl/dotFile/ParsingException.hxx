/*
 * GraphException.hxx
 *
 *  Created on: 19 janv. 2015
 *      Author: maeln
 */

#ifndef DSGL_PARSINGEXCEPTION_HXX_
#define DSGL_PARSINGEXCEPTION_HXX_

#include <exception>
#include <string>

class ParsingException: public std::exception
{
	public:
		ParsingException(const char *msg) : err_msg(msg)
		{
		};

		~ParsingException() throw ()
		{
		};

		const char* what() const throw ()
		{
			return this->err_msg.c_str();
		};

	private:
		std::string err_msg;

};

#endif /* DSGL_PARSINGEXCEPTION_HXX_ */
