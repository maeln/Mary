#ifndef GRAPH_HXX
#define GRAPH_HXX

#include <string>
#include <vector>
#include <set>
#include "Node.hxx"

class Graph
{
	public:
		Graph();
		~Graph();

		// Getter.
		unsigned int nodes_size();
		Node* get_node(unsigned int id);
		Node* get_node(std::string node);
		std::set<Node*> get_neighbors(Node* node, unsigned int depth);

		// Modifier.
		Node* add_node_by_name(std::string name);
		Node* add_node(Node* node);

		void link_nodes_by_name(std::string lhs, std::string rhs);
		void link_nodes(Node* lhs, Node* rhs);

		std::string to_string();

	private:
		std::vector<Node*> m_nodes;
};

#endif
