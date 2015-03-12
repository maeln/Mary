// Author : Maël Naccache.

#ifndef NOTESCOUNTER_HXX
#define NOTESCOUNTER_HXX

#include <vector>
#include <map>
#include "notes.hxx"

class NotesCounter
{
	public:
		NotesCounter();
		~NotesCounter();
		
		void addNote(Notes note);
		unsigned int getCount(Notes note);
		std::vector<Notes> getAllNotes();

	private:
		std::map<Notes, unsigned int> counter;
};

#endif

