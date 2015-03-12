// Author : Maël Naccache.

#ifndef NOTES_HXX
#define NOTES_HXX

#include <string>

class Notes
{
	public:
		Notes(std::string name, double freq);
		~Notes();
		
		std::string getName();
		double getFreq(double octave);

		inline bool operator==(const Notes& o) const
		{
			return (m_name == o.m_name);
		}

		inline bool operator<(const Notes& o) const
		{
			return (m_freq < o.m_freq);
		}

	private:
		std::string m_name;
		double m_freq;
};

#endif

