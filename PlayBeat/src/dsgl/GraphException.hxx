/*
 * GraphException.hxx
 *
 *  Created on: 19 janv. 2015
 *      Author: maeln
 */

#ifndef DSGL_GRAPHEXCEPTION_HXX_
#define DSGL_GRAPHEXCEPTION_HXX_

#include <exception>
#include <string>

class GraphException: public std::exception
{
	public:
		GraphException(const char *msg) : err_msg(msg)
		{
		};

		~GraphException() throw ()
		{
		};

		const char* what() const throw ()
		{
			return this->err_msg.c_str();
		};

	private:
		std::string err_msg;

};

#endif /* DSGL_GRAPHEXCEPTION_HXX_ */
