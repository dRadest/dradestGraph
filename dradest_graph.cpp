#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
    // TODO: replace with set later to keep adjacency lists sorted
    std::sort(adj[u].begin(), adj[u].end());
    std::sort(adj[w].begin(), adj[w].end());
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
  // check if n is valid
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

std::vector<int> dradestGraph::iterativeDFS(int n)
{
  // save dfs 
  std::vector<int> dfs;
  // check if n is valid
  if(n >= V){
    std::cout << "Node " << n << " invalid. Exiting DFS.\n";
    return dfs;
  }
  // mark all nodes as unvisited
  bool *visited = new bool[V]; 
  for(int i = 0; i < V; i++){
    visited[i] = false;
  }
  
  // stack for depth first search
  stack<int> stack; 
  
  // push the starting node unto stack 
  stack.push(n); 

  std::cout << "Iterative DFS from node " << n << ": ";
  
  while (!stack.empty()) 
  { 
    // pop a node from the stack
    n = stack.top(); 
    stack.pop(); 

    if(visited[n]) // ignore it if already visited
    {
      continue;
    }

    // mark n as visited and print it
    cout << n << " "; 
    dfs.push_back(n);
    visited[n] = true; 
    
    // traverse adjacency list of node n in reverse order
    for (auto it = adj[n].rbegin(); it != adj[n].rend(); ++it) {
        if (!visited[*it]){
          stack.push(*it);
        }  
    } 
  }
  std::cout << "\n";
  return dfs;
}

void dradestGraph::helpDFS(int n, bool visited[], std::vector<int>* dfs) 
{ 
  // mark the current node as visited and print it 
  visited[n] = true; 
  cout << n << " "; 
  dfs -> push_back(n);
  
  // traverse adjacency list of current node
  for(auto it = adj[n].begin(); it != adj[n].end(); ++it) {
      if(!visited[*it]) {
          helpDFS(*it, visited, dfs); 
      }
  }
} 

std::vector<int> dradestGraph::recursiveDFS(int n) 
{ 
  vector<int> dfs;
  // check if n is valid
  if(n >= V){
    std::cout << "Node " << n << " invalid. Exiting DFS.\n";
    return dfs;
  }
  std::cout << "Recursive DFS from node " << n << ": ";
  // mark all the vertices as not visited 
  bool *visited = new bool[V]; 
  for (int i = 0; i < V; i++) {
      visited[i] = false; 
  }

  // call the helper dfs function
  helpDFS(n, visited, &dfs);
  std::cout << "\n";
  return dfs;
   
} 