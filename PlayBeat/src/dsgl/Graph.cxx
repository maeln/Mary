#include "Graph.hxx"

#include <iostream>
#include <map>
#include <queue>
#include <utility>

#include "GraphException.hxx"

Graph::Graph()
{

}

Graph::~Graph()
{
	for(unsigned int i=0; i<m_nodes.size(); ++i)
		delete m_nodes[i];
	m_nodes.clear();
}

unsigned int Graph::nodes_size()
{
	return m_nodes.size();
}

Node* Graph::get_node(unsigned int id)
{
	if(id <= m_nodes.size())
		return m_nodes[id];
	else
		return NULL;
}

Node* Graph::get_node(std::string name)
{
	Node* res = NULL;
	for(unsigned int i=0; i<m_nodes.size(); ++i)
	{
		if(m_nodes[i]->get_name() == name)
		{
			res = m_nodes[i];
			break;
		}
	}

	return res;
}

std::set<Node*> Graph::get_neighbors(Node* node, unsigned int depth)
{
	std::set<Node*> res;
	std::queue<Node*> file;
	unsigned int rec = depth;
	file.push(node);
	res.insert(node);

	while(!file.empty() && rec > 0)
	{
		Node* s = file.front();
		file.pop();
		for(unsigned int i=0; i<s->neighbors_size(); ++i)
		{
			if(res.find(s->get_neighbors(i)) == res.end())
			{
				file.push(s->get_neighbors(i));
				res.insert(s->get_neighbors(i));
			}
		}
		rec--;
	}

	return res;
}

Node* Graph::add_node_by_name(std::string name)
{
	bool present = false;
	Node* res = NULL;
	for(unsigned int i = 0; i < m_nodes.size(); ++i)
	{
		if(m_nodes[i]->get_name() == name)
		{
			res = m_nodes[i];
			present = true;
			break;
		}
	}

	if(present)
	{
		return res;
	}
	else
	{
		Node* node = new Node(name);
		m_nodes.push_back(node);
		return m_nodes.back();
	}
}

Node* Graph::add_node(Node* node)
{
	bool present = false;
	Node* res = NULL;
	for(unsigned int i = 0; i < m_nodes.size(); ++i)
	{
		if(m_nodes[i] == node)
		{
			res = m_nodes[i];
			present = true;
			break;
		}
	}

	if(present)
		return res;
	else
	{
		m_nodes.push_back(node);
		return m_nodes.back();
	}
}

void Graph::link_nodes_by_name(std::string lhs, std::string rhs)
{
	Node* nl = get_node(lhs);
	if(nl == NULL) throw GraphException("Missing node.");
	Node* nr = get_node(rhs);
	if(nr == NULL) throw GraphException("Missing node.");
	nl->add_neighbors(nr);
	nr->add_neighbors(nl);

}

void Graph::link_nodes(Node* lhs, Node* rhs)
{
	lhs->add_neighbors(rhs);
	rhs->add_neighbors(lhs);
}

std::string Graph::to_string()
{
	std::string res("graph G {\n");
	for(unsigned int i=0; i<m_nodes.size(); ++i)
	{
		Node* cur = m_nodes[i];
		std::cout << "nn:" << cur->get_name() << std::endl;
		for(unsigned int n=0; n<cur->neighbors_size(); ++n)
		{
			res.append(cur->get_name());
			res.append("--");
			res.append(cur->get_neighbors(n)->get_name());
			res.append(";\n");
		}
	}
	res.append("}\n");

	return res;
}
