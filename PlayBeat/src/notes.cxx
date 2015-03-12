#include <cmath>
#include "notes.hxx"

// Note : Fréquence d'une note dans la gamme tempéré (wikipedia) :
// f0 : frequence de départ, alors fn = f0 * 2^(n/12)
// n = nb de demi-ton au dessus de f0.
// 1 octave = 12 demi-ton.
// ex: La : f0 = 55.0, 3ème octave : f0*2.0^(3.0*12.0/12.0) = 440Hz.

Notes::Notes(std::string name, double freq) 
{
	m_freq = freq;
	m_name = name;
}

Notes::~Notes()
{

}

std::string Notes::getName()
{
	return m_name;
}

double Notes::getFreq(double octave)
{
	return m_freq * pow(2.0, octave);
}

/*
friend bool Notes::operator==(const Notes& o)
{
	return (m_name == o.getName());
}

bool Notes::operator<(const Notes& o)
{
	return (this.getFreq(0.0) < o.getFreq(0.0));
}
*/

