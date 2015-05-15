/*
 * BDDManager.hxx
 *
 *  Created on: 26 mars 2015
 *      Author: maeln
 */

#ifndef BDD_BDDMANAGER_HXX_
#define BDD_BDDMANAGER_HXX_

#include <sqlite3.h>
#include <string>
#include "../MusicMetadata.hxx"

class BDDManager
{
public:
	BDDManager(std::string bd_path);
	~BDDManager();

	/**
	 * Add music metadata to the sqlite database.
	 * \param md : Music Metadata to save in the database
	 * \return Error code :
	 * 		- 0 : OK
	 * 		- 1 : FAIL
	 * 		- 2 : Duplicata
	 **/
	int add_music_metadata(MusicMetadata md);


private:
	sqlite3 *m_bdd;
	sqlite3_stmt *m_stmt;
};

#endif /* BDD_BDDMANAGER_HXX_ */

