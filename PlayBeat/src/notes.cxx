#include "notes.hxx"
#include <sstream>

// Note : Fréquence d'une note dans la gamme tempéré (wikipedia) :
// f0 : frequence de départ, alors fn = f0 * 2^(n/12)
// n = nb de demi-ton au dessus de f0.
// 1 octave = 12 demi-ton.
// ex: La : f0 = 55.0, 3ème octave : f0*2.0^(3.0*12.0/12.0) = 440Hz.

Notes::Notes()
{
	m_freq = 0.0;
	m_name = "";
	m_octave = 0.0;
}

Notes::Notes(std::string name, double freq, double octave)
{
	m_freq = freq;
	m_name = name;
	m_octave = octave;
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

std::string Notes::getNameWithOctave()
{
	std::stringstream ss;
	ss << m_name << "-" << m_octave;
	return ss.str();
}

double Notes::getOctave()
{
	return m_octave;
}
