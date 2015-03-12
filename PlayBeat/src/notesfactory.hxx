// Author : Maël Naccache

#ifndef NOTESFACTORY_HXX
#define NOTESFACTORY_HXX

#include <vector>
#include "notes.hxx"

class NotesFactory
{
	public:
		NotesFactory();
		~NotesFactory();
		
		double findOctave(double frequency);
		Notes getNote(double frequency);

	private:
		std::vector<Notes> fondamentales;
};

#endif
