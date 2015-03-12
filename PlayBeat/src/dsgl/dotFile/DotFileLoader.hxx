/*
 * DotFileLoader.hxx
 *
 *  Created on: 21 janv. 2015
 *      Author: maeln
 */

#ifndef DSGL_DOTFILE_DOTFILELOADER_HXX_
#define DSGL_DOTFILE_DOTFILELOADER_HXX_

#include <string>

class Graph;

class DotFileLoader
{
	public:
		DotFileLoader();
		virtual ~DotFileLoader();
		Graph* load(std::string file);
};

#endif /* DSGL_DOTFILE_DOTFILELOADER_HXX_ */
