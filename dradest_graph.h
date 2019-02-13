#ifndef DRADEST_GRAPH_H
#define DRADEST_GRAPH_H

#include <vector>

// undirected graph using adjacency list representation
class dradestGraph 
{ 
private:
    int V; // number of vertices 
  
    // Pointer to an array containing adjacency lists 
    std::vector<int> *adj;    
public: 
    dradestGraph(int x);  // Constructor 
    // utility function to add an edge between u and w
    void addEdge(int u, int w);
    // utility function to print the adjacency list representation of the graph
    void printGraph();
}; 
 
#endif