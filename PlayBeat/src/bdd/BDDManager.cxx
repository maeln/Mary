//
// Created by maeln on 11/05/15.
//

#include <iostream>
#include <sqlite3.h>
#include "BDDManager.hxx"

BDDManager::BDDManager(std::string db_path)
{
    int rc;

    rc = sqlite3_open(db_path.c_str(), &m_bdd);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot Open/Create database playbeat.db" << std::endl;
        sqlite3_close(m_bdd);
    }
}

BDDManager::~BDDManager()
{
    sqlite3_finalize(m_stmt);
    sqlite3_close(m_bdd);
}

int BDDManager::add_music_metadata(MusicMetadata md)
{
    char *zErrMsg = 0;

    // First of, check for duplicata.
    std::stringstream check_dup;
    check_dup << "SELECT ID FROM MUSICMETADATA\n";
    check_dup << "WHERE MUSICMETADATA.NAME == '" << md.title << "'\n";
    check_dup << "AND MUSICMETADATA.ARTISTS == '" << md.artists << "';";

    int ret;
    ret = sqlite3_prepare_v2(m_bdd, check_dup.str().c_str(), -1, &m_stmt, 0);
    if (ret != SQLITE_OK)
        return 1;

    // fetch a row's status
    ret = sqlite3_step(m_stmt);
    if (ret == SQLITE_ROW)
    {
        return 2;
    }

    sqlite3_reset(m_stmt);

    std::stringstream insert;
    insert << "INSERT INTO MUSICMETADATA (NAME, ARTISTS, GENRE, LENGTH, BPM) VALUES (";
    insert << "'" << md.title << "', ";
    insert << "'" << md.artists << "', ";
    insert << "'" << md.genre << "', ";
    insert << md.length << ", ";
    insert << md.bpm << ");";

    ret = sqlite3_prepare_v2(m_bdd, insert.str().c_str(), -1, &m_stmt, 0);
    if (ret != SQLITE_OK)
        return 1;

    ret = sqlite3_step(m_stmt);
    if (ret != SQLITE_DONE)
        return 1;

    sqlite3_reset(m_stmt);

    return 0;
}

