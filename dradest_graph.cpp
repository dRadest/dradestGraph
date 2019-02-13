#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

std::vector<int> dradestGraph::BFS(int n)
{
  // save bfs 
  std::vector<int> bfs;
  // check if n valid
  if(n >= V){
    std::cout << "Node " << n << " invalid. Exiting BFS.\n";
    return bfs;
  }
  // mark all nodes as unvisited
  bool *visited = new bool[V]; 
  for(int i = 0; i < V; i++){
    visited[i] = false;
  }

  // queue for breadth first search
  std::queue<int> q;  
  
  // mark the starting node as visited and enqueue it 
  visited[n] = true; 
  q.push(n); 
  
  // iterator for iterating adjacency list of node n
  std::vector<int>::iterator it; 

  std::cout << "BFS from node " << n << ": ";
  
  while(!q.empty()) 
  { 
    // dequeue a node from queue 
    n = q.front(); 
    std::cout << n << " ";
    bfs.push_back(n); 
    q.pop(); 

    // traverse all adjacent nodes of node n
    for (it = adj[n].begin(); it != adj[n].end(); ++it) 
    { 
      if (!visited[*it]) // mark as visited and enqueue it
      { 
          visited[*it] = true; 
          q.push(*it); 
      } 
    } 
  } 
  std::cout << "\n";
  return bfs;
}