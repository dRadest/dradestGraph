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
    // helper function used by recursiveDFS()
    void helpDFS(int n, bool visited[], std::vector<int>* dfs);
public: 
    dradestGraph(int x);  // Constructor 
    // utility function to add an edge between u and w
    void addEdge(int u, int w);
    // utility function to print the adjacency list representation of the graph
    void printGraph();
    // utility function to perform a breadth first search starting from node n
    std::vector<int> BFS(int n);
    // utility function to perform a depth first search starting from node n, iteratively
    std::vector<int> iterativeDFS(int n);
    // utility function to perform a depth first search starting from node n, recursively
    std::vector<int> recursiveDFS(int n);

}; 
 
#endif