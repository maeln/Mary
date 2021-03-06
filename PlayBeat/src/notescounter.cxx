#include "notescounter.hxx"

NotesCounter::NotesCounter()
{
}

NotesCounter::~NotesCounter()
{
}

void NotesCounter::addNote(Notes note)
{
	int pos = searchNote(note);
	if(pos >= 0)
	{
		m_counter[pos] = m_counter[pos] + 1;
	}
	else
	{
		m_notes.push_back(note);
		m_counter[m_notes.size()-1] = 1;
	}
}

unsigned int NotesCounter::getCount(Notes note)
{
	int pos = searchNote(note);
	if(pos >= 0)
		return m_counter[pos];
	else
		return 0;
}

std::vector<Notes> NotesCounter::getAllNotes()
{
	std::vector<Notes> notes;
	for (std::map<unsigned int, unsigned int>::iterator it=m_counter.begin(); it!=m_counter.end(); ++it)
		    notes.push_back(m_notes[it->first]);

	return notes;
}

int NotesCounter::searchNote(Notes note)
{
	int pos = -1;
	for(unsigned int i=0; i < m_notes.size(); ++i)
	{
		if(m_notes[i] == note)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

std::vector<Notes> NotesCounter::getSortedNotes()
{
	std::vector<unsigned int> notesid;
	for (std::map<unsigned int, unsigned int>::iterator it=m_counter.begin(); it!=m_counter.end(); ++it)
			    notesid.push_back(it->first);
	notesid = mergeSort(notesid);
	std::vector<Notes> notes(notesid.size());
	for(unsigned int i=0; i<notesid.size(); ++i)
	{
		notes[i] = m_notes[notesid[i]];
	}
	return notes;
}

std::vector<unsigned int> NotesCounter::mergeSort(std::vector<unsigned int> noteid)
{
	if(noteid.size() <= 1)
		return noteid;
	unsigned int middle = noteid.size()/2;
	std::vector<unsigned int> left, right;
	for(unsigned int i=0; i<middle; ++i)
		left.push_back(noteid[i]);
	for(unsigned int i=middle; i<noteid.size(); ++i)
		right.push_back(noteid[i]);
	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}

std::vector<unsigned int> NotesCounter::merge(std::vector<unsigned int> left, std::vector<unsigned int> right)
{
	std::vector<unsigned int> res;
	while(!left.empty() && !right.empty())
	{
		if(m_counter[left.front()] >= m_counter[right.front()])
		{
			res.push_back(left.front());
			left = std::vector<unsigned int>(left.begin()+1, left.end());
		}
		else
		{
			res.push_back(right.front());
			right = std::vector<unsigned int>(right.begin()+1, right.end());
		}
	}
	while(!left.empty())
	{
		res.push_back(left.front());
		left = std::vector<unsigned int>(left.begin()+1, left.end());
	}
	while(!right.empty())
	{
		res.push_back(right.front());
		right = std::vector<unsigned int>(right.begin()+1, right.end());
	}
	return res;
}
