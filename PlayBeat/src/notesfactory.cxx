#include <cmath>
#include "notesfactory.hxx"

#include <stdexcept>

NotesFactory::NotesFactory()
{
	Notes fund("do", 32.70, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("do#", 34.65, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("re", 36.71, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("re#", 38.89, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("mi", 41.20, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("fa", 43.65, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("fa#", 46.25, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("sol", 49.00, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("sol#", 51.91, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("la", 55.00, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("la#", 58.27, 0.0);
	fondamentales.push_back(fund);
	
	fund = Notes("si", 61.74, 0.0);
	fondamentales.push_back(fund);
}

NotesFactory::~NotesFactory()
{
}

double NotesFactory::findOctave(double frequency)
{
	double octave = 0.0;
	Notes fundMax = fondamentales.back();
	while(frequency > fundMax.getFreq(octave))
	{
		octave += 1.0;
	}

	return octave;
}

Notes NotesFactory::getNote(double frequency)
{
	double octave = findOctave(frequency);

	Notes borneInf = fondamentales.front();
	Notes borneSup = fondamentales.back();

	if(frequency < borneInf.getFreq(0))
	{
		throw std::logic_error("bad frequency");
	}
	
	for(unsigned int i=0; i<(fondamentales.size()-1); ++i)
	{
		borneInf = fondamentales.at(i);
		borneSup = fondamentales.at(i+1);

		if(borneInf.getFreq(octave) >= frequency
				&& frequency <= borneSup.getFreq(octave))
		{
			break;
		}
	}

	double diffInf = std::abs(borneInf.getFreq(octave) - frequency);
	double diffSup = std::abs(borneSup.getFreq(octave) - frequency);
	
	if(diffInf > diffSup)
		return Notes(borneSup.getName(), frequency, octave);
	else
		return Notes(borneInf.getName(), frequency, octave);
}

