#include "notescounter.hxx"

NotesCounter::NotesCounter()
{
}

NotesCounter::~NotesCounter()
{
}

void NotesCounter::addNote(Notes note)
{
	if(counter.find(note) == counter.end())
		counter[note] = 1;
	else
		counter[note] = counter[note] + 1;
}

unsigned int NotesCounter::getCount(Notes note)
{
	if(counter.find(note) == counter.end())
		return 0;
	else
		return counter[note];

}

std::vector<Notes> NotesCounter::getAllNotes()
{
	std::vector<Notes> notes;
	for (std::map<Notes, unsigned int>::iterator it=counter.begin(); it!=counter.end(); ++it)
		    notes.push_back(it->first);

	return notes;
}

