#include <iostream>
#include <algorithm> 
#include <vector>  

using namespace std;

#include "dradest_graph.h"


// demonstrating functionality of dradest graph
int main()
{
	// construct a graph
	dradestGraph graph(5);
	// add edges
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(2, 3);
	graph.addEdge(3, 1);
	graph.addEdge(0, 4);
	graph.addEdge(1, 4);
	graph.addEdge(3, 4);
	graph.addEdge(4, 0); // testing inserting duplicate

	/*** constructed graph

			0
		   / \
		  4___1
		   \  |\
		    \ | 2
		     \|/
		      3

    ********************/

    // print adjacency list of each node
    graph.printGraph();

    // perform breadth first search
    graph.BFS(0);
    graph.BFS(3);
    graph.BFS(5); // invalid node

    // preform depth first search
    graph.iterativeDFS(0);
    std::vector<int> idfs = graph.iterativeDFS(3);
    graph.iterativeDFS(5); // invalid node

    graph.recursiveDFS(0);
    std::vector<int> rdfs = graph.recursiveDFS(3);
    graph.recursiveDFS(5); // invalid node

    std::cout << "do iterative and recursive approach yield same result? " << (idfs==rdfs ? "yes" : "no") << "\n";  

    // use DFS to check if graph contains a cycle
    std::cout << "DFS check for cycle returns: " << graph.hasCycle() << "\n";

    // use union find to check if the graph contains a cycle
    std::cout << "UF check for cycle returns: " << graph.containsCycle() << "\n";

    // construct acyclic graph
    dradestGraph dg(7);
    dg.addEdge(0,1);
    dg.addEdge(0,2);
    dg.addEdge(2,5);
    dg.addEdge(2,3);
    dg.addEdge(2,4);
    dg.addEdge(4,6); // TODO: safety check for index out of bounds

    // print acyclic graph adjacency list
    dg.printGraph();

    std::cout << "UF check for cycle returns: " << dg.containsCycle() << "\n";

    return 0;
}