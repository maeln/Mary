/*
 * MusicMetadata.hpp
 *
 *  Created on: 12 mars 2015
 *      Author: maeln
 */

#ifndef MUSICMETADATA_HXX_
#define MUSICMETADATA_HXX_

#include <string>
#include <vector>
#include <sstream>

#include "notes.hxx"

class MusicMetadata
{
	public:
		std::string title;
		std::string artists;
		std::string genre;
		int length;
		int bpm;
		std::vector<Notes> topNotes;

		std::string toString()
		{
			std::stringstream ss;
			ss << "==" << title << ", by: " << artists << "==" << std::endl;
			ss << "Genre: " << genre << ", length: "<< (length - length%60)/60 << ":" << length%60 << ", bpm: " << bpm << std::endl;
			ss << "Top Notes (descending order): " << topNotes[0].getNameWithOctave();
			for(unsigned int i=1; i<topNotes.size(); ++i)
				ss << ", " << topNotes[i].getNameWithOctave();
			return ss.str();
		}
};

#endif /* MUSICMETADATA_HXX_ */
