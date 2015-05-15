/*
 * BDDManager.hxx
 *
 *  Created on: 26 mars 2015
 *      Author: maeln
 */

#ifndef BDD_BDDMANAGER_HXX_
#define BDD_BDDMANAGER_HXX_

#include <sqlite3.h>
#include "../MusicMetadata.hxx"

class BDDManager
{
public:
	/**
	 * Singleton pattern, get (or create) the current instance of
	 * BDDManager.
	 **/
	static BDDManager& get_instance() {
		static BDDManager inst;
		return inst;
	}

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
	BDDManager();
	BDDManager(BDDManager const&);
	BDDManager& operator==(BDDManager const&);
	~BDDManager();

	sqlite3 *m_bdd;
	sqlite3_stmt *m_stmt;
};

#endif /* BDD_BDDMANAGER_HXX_ */

