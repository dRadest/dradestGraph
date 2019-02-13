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

  
    return 0;
}