#include <iostream>
#include <vector>
#include <algorithm>
#include "dradest_graph.h"
using namespace std;
 
dradestGraph::dradestGraph(int x)
{
  V = x;
  adj = new vector<int>[V];
  std::cout << "graph constructed" << endl;
}

void dradestGraph::addEdge(int u, int w)
{
  if(std::find(adj[u].begin(), adj[u].end(), w) == adj[u].end())
  {
    adj[u].push_back(w);
    adj[w].push_back(u);
  }
  else
  {
    cout << "edge " << u << " - " << w << " already exists!\n";
  }
}

void dradestGraph::printGraph() 
{ 
  for (int i=0; i < V; ++i) 
  { 
    std::cout << "Adjacency list of node " << i << ": "; 
    for (int j=0; j < adj[i].size(); ++j)
    {
      std::cout << adj[i].at(j) << (j==adj[i].size()-1 ? "\n" : " -> ");
    }
  } 
} 