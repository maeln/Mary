#ifndef NODE_HXX
#define NODE_HXX

#include <string>
#include <vector>

class Node
{
	public:
		Node(std::string name);
		~Node();
		
		// Getter related functions.
		std::string get_name();
		unsigned int neighbors_size();
		Node* get_neighbors(unsigned int id);
		Node* search_neighbors_by_name(std::string name);
		Node* search_neighbors(Node* node);

		// Setter related functions.
		void add_neighbors(Node* node);

		bool operator==(Node& node);

	private:
		std::string m_name;
		std::vector<Node*> m_neighbors;
};

#endif
