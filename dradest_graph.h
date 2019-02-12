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
}; 
 
#endif