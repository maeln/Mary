#include <iostream>
#include <string>

#include <sqlite3.h>

#include "MusicMetadata.hxx"
#include "playbeat.hxx"
#include "tools/StringFormat.hxx"
#include "bdd/BDDManager.hxx"

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

	BDDManager bdd("/home/maeln/projects/Mary/PlayBeat/playbeat.db");
	int code = bdd.add_music_metadata(meta);
	std::cout << "DB WRITE CODE: " << code  << std::endl;

	return 0;
}

