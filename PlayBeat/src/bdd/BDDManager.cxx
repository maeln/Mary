//
// Created by maeln on 11/05/15.
//

#include <iostream>
#include "BDDManager.hxx"

BDDManager::BDDManager()
{
	int rc;

	rc = sqlite3_open("playbeat.db", &m_bdd);
	if (rc) {
		std::cerr << "Cannot Open/Create database playbeat.db" << std::endl;
		sqlite3_close(m_bdd);
	}
}

BDDManager::~BDDManager()
{
	sqlite3_close(m_bdd);
}

int BDDManager::add_music_metadata(MusicMetadata md)
{
	char* zErrMsg = 0;

	// First of, check for duplicata.
	bool dups = false;
	std::string check_dup = "SELECT ID FROM MUSICMETADATA \n"
							"WHERE MUSICMETADATA.NAME == 'R'\n"
							"AND MUSICMETADATA.ARISTS == 'l';";
	int ret;
	ret = sqlite3_prepare_v2(m_bdd, check_dup.c_str(), -1, &m_stmt, 0);
	if(ret)
		return 1;

	// fetch a row's status
	ret = sqlite3_step(m_stmt);
	if(ret == SQLITE_ROW)
	{
		dups = true;
	}

	sqlite3_finalize(m_stmt);

	std::stringstream stream;
	stream << "INSERT INTO MUSICMETADATA (NAME, ARTISTS, GENRE, LENGTH, BPM) VALUES (";
	stream << "\"" << md.title << "\", ";
	stream << "\"" << md.artists << "\", ";
	stream << "\"" << md.genre << "\", ";
	stream << md.length << ", ";
	stream << md.bpm << ");";
}

