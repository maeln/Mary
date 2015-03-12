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
		std::vector<Notes> getSortedNotes();

		int searchNote(Notes note);

	private:
		std::vector<unsigned int> mergeSort(std::vector<unsigned int> noteid);
		std::vector<unsigned int> merge(std::vector<unsigned int> left, std::vector<unsigned int> right);
		std::vector<Notes> m_notes;
		std::map<unsigned int, unsigned int> m_counter;
};

#endif

