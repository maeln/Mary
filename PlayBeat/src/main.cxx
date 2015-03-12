#include <iostream>
#include <map>
#include <set>
#include <string>

#include "dsgl/dotFile/DotFileLoader.hxx"
#include "dsgl/Graph.hxx"
#include "dsgl/Node.hxx"
#include "playbeat.hxx"

int main(int argc, char** argv)
{
	std::string audioPath(argv[1]);
	PlayBeat b(audioPath);

	std::string graphPath(argv[2]);
	DotFileLoader loader;
	Graph* g = loader.load(graphPath);

	std::cout << g->to_string() << std::endl;

	std::set<Node*> neighbors = g->get_neighbors(g->get_node("blues"), 1);
	for(std::set<Node*>::iterator it=neighbors.begin(); it!=neighbors.end(); ++it)
		std::cout << ((Node*)*it)->get_name() << std::endl;

	delete g;

	return 0;
}
