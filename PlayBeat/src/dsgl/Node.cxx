#include "Node.hxx"

#include <cstddef>
#include <iostream>

#include "GraphException.hxx"

Node::Node(std::string name)
{
	std::size_t found = name.find('\0');
	if(found!=std::string::npos || name.empty())
		throw GraphException("Empty string in node constructor.");
	std::cout << "n: " << name << std::endl;
	m_name = name;
}

Node::~Node()
{
	//m_neighbors.clear();
}

std::string Node::get_name()
{
	return m_name;
}

unsigned int Node::neighbors_size()
{
	return m_neighbors.size();
}

Node* Node::get_neighbors(unsigned int id)
{
	if(id <= m_neighbors.size())
		return m_neighbors[id];
	return NULL;
}

Node* Node::search_neighbors_by_name(std::string name)
{
	Node* res = NULL;
	for(unsigned int i = 0; i < m_neighbors.size(); ++i)
	{
		if(m_neighbors[i]->get_name() == m_name)
		{
			res = m_neighbors[i];
			break;
		}
	}

	return res;
}

Node* Node::search_neighbors(Node* node)
{
	Node* res = NULL;
	for(unsigned int i = 0; i < m_neighbors.size(); ++i)
	{
		if(*m_neighbors[i] == *node)
		{
			res = m_neighbors[i];
			break;
		}
	}

	return res;
}

void Node::add_neighbors(Node* node)
{
	if(!search_neighbors(node))
	{
		m_neighbors.push_back(node);
	}
}

bool Node::operator==(Node& node)
{
	return (m_name == node.m_name);
}
