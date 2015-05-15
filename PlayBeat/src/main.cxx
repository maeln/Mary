#include <iostream>
#include <string>

#include <sqlite3.h>

#include "MusicMetadata.hxx"
#include "playbeat.hxx"
#include "tools/StringFormat.hxx"

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++){
		std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	return 0;
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cerr << "Usage Playbeat <music file>" << std::endl;
		exit(1);
	}

	std::string audioPath(argv[1]);
	PlayBeat b;
	MusicMetadata meta = b.getMetadata(audioPath);
	std::cout << meta.toString() << std::endl;

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;

	rc = sqlite3_open("playbeat.db", &db);
	if(rc)
	{
		std::cerr << "Cannot Open/Create database playbeat.db" << std::endl;
		sqlite3_close(db);
	}

	std::string sql_req = "CREATE TABLE `MUSICMETADATA` (`ID` INTEGER PRIMARY KEY, "
			"`NAME` TEXT NOT NULL, `ARTISTS` TEXT NOT NULL, `GENRE` TEXT NOT NULL, `LENGTH` INT NOT NULL, `BPM` INT NOT NULL);";

	//std::string sql_req = "SELECT name FROM sqlite_master WHERE type='table'  AND name='MUSICMETADATA';";

	rc = sqlite3_exec(db, sql_req.c_str(), callback, 0, &zErrMsg);
	if( rc!=SQLITE_OK )
	{
		std::cerr << "SQL error : " << zErrMsg << std::endl;;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);

	/*
	std::string graphPath(argv[2]);
	DotFileLoader loader;
	Graph* g = loader.load(graphPath);

	std::cout << g->to_string() << std::endl;

	std::set<Node*> neighbors = g->get_neighbors(g->get_node("blues"), 1);
	for(std::set<Node*>::iterator it=neighbors.begin(); it!=neighbors.end(); ++it)
		std::cout << ((Node*)*it)->get_name() << std::endl;

	delete g;
	 */

	return 0;
}

