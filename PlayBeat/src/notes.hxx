// Author : Maël Naccache.

#ifndef NOTES_HXX
#define NOTES_HXX

#include <string>
#include <cmath>

class Notes
{
	public:
		Notes();
		Notes(std::string name, double freq, double octave);
		~Notes();
		
		std::string getName();
		std::string getNameWithOctave();
		double getFreq(double octave);
		double getOctave();

		inline bool operator==(const Notes& o) const
		{
			return ((m_name == o.m_name) && (floor(m_octave - o.m_octave) < 1.0));
		}


		inline bool operator<(const Notes& o) const
		{
			return ((m_freq*pow(2.0,m_octave)) < (o.m_freq*pow(2.0,o.m_octave)));
		}

	private:
		std::string m_name;
		double m_freq;
		double m_octave;
};

#endif

