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
    cout << "edge " << u << " - " << w << " already exists!" << endl;
  }
}