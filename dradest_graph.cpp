#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h> 
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

bool dradestGraph::helpCycle(int n, bool visited[], int parent) 
{ 
  // mark the current node as visited 
  visited[n] = true; 

  // traverse adjacent nodes
  for (auto it = adj[n].begin(); it != adj[n].end(); ++it) 
  { 
    // recur for adjacent unvisited nodes
    if (!visited[*it]) 
    { 
     if (helpCycle(*it, visited, n)) 
      return true; 
  } 

    // adjacent node visited and not a parent of current node
  else if (*it != parent) {
    return true;
  }
} 
return false; 
} 

bool dradestGraph::hasCycle()
{ 
  // initally, all nodes are not visited
  bool *visited = new bool[V]; 
  for (int i = 0; i < V; i++) {
    visited[i] = false; 
  }

  // call helpCycle() to detect a cycle in different DFS trees
  for (int i = 0; i < V; i++) {
    if (!visited[i]) { 
      if (helpCycle(i, visited, -1)) {
        return true; 
      }
    }
  }

  return false; 
} 

// uses path compression technique 
// (i.e. keeps found root of i as its parent)
int dradestGraph::find(struct subset subsets[], int i)
{
  if(subsets[i].parent != i)
  {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

// uses union by rank to do union of sets x and y
void dradestGraph::Union(struct subset subsets[], int x, int y)
{
  // find root of x and y
  int xroot = find(subsets, x); 
  int yroot = find(subsets, y); 

  // attach smaller rank tree under root of high rank tree  
  if (subsets[xroot].rank < subsets[yroot].rank) 
  {
    subsets[xroot].parent = yroot; 
  }
  else if (subsets[xroot].rank > subsets[yroot].rank) 
  {
    subsets[yroot].parent = xroot; 
  }

  // make one as root and increment its rank by one 
  else
  { 
    subsets[yroot].parent = xroot; 
    subsets[xroot].rank++; 
  } 
}

bool dradestGraph::containsCycle()
{
  // create a working copy of adjacency list
  std::vector<int> *wadj = new vector<int>[V];
  for(int i=0; i<V; i++)
  {
    wadj[i] = adj[i];
  }

  // memory for creatng V subsets
  struct subset* subsets = new subset[V]; 
  // initialize all nodes to be in their own set 
  for (int i = 0; i < V; i++)
  { 
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }

  // traverse adjacency list
  for(int i=0; i<V; ++i)
  {
    // traverse adjacent nodes (i.e. edges) of the current node
    for(auto it=wadj[i].begin(); it != wadj[i].end(); ++it)
    {
      int x = find(subsets, i);
      int y = find(subsets, *it);
      if(x == y)
      {
        return true;
      }
      Union(subsets, x, y);
      // remove current node from y's list of adjacent nodes
      auto index = std::lower_bound(wadj[*it].begin(), wadj[*it].end(), i);
      wadj[*it].erase(index);
    }
  }
  
  return false; 
}

std::vector<int>* dradestGraph::primMST()
{
  // construct MST as an adjacency list
  std::vector<int> *wadj = new std::vector<int>[V];

  // set of included nodes in the MST
  bool included[V];
  for(int i=0; i<V; ++i) // initialize all to false
  {
    included[i] = false;
  }

  // include the first node in the MST
  included[0] = true;
  // keep track of nodes included so we can return early if needs be
  int pushed = 1;
  for(int i=0; i<V; ++i)
  {
    for(auto it=adj[i].begin(); it!=adj[i].end(); ++it)
    {
      if(!included[*it])
      {
        wadj[i].push_back(*it);
        included[*it] = true;
        pushed++;
      }
      if(pushed >= V)
      {
        return wadj;
      }
    }
  }
  return wadj;
}

std::vector<int>* dradestGraph::kruskalMST()
{
  // construct MST as an adjacency list
  std::vector<int> *wadj = new std::vector<int>[V];

  // memory for creatng V subsets
  struct subset* subsets = new subset[V]; 
  // initialize all nodes to be in their own set 
  for (int i = 0; i < V; i++)
  { 
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }

  // keep track of edges added
  int edges = 0;
  // current node 
  int i = 0;
  while(edges < V-1)
  {
    // traverse adjacent nodes of the current node (i)
    for(auto it=adj[i].begin(); it!=adj[i].end(); ++it)
    {
      // check if this edge forms a cycle
      int x = find(subsets, i);
      int y = find(subsets, *it);
      if(x != y)
      {
        // add the edge
        wadj[i].push_back(*it);
        // perform union on the two nodes
        Union(subsets, x, y);
        edges++;
      }
    }
    i++;
  }
  return wadj;
}

int dradestGraph::minDistance(int distance[], bool included[]) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < V; v++) 
   {
     if (included[v] == false && distance[v] <= min)
     {
       min = distance[v]; 
       min_index = v; 
     } 
   }
   
   return min_index; 
} 

void dradestGraph::dijkstraSPT(int root)
{
  // set of included nodes in the MST
  bool included[V];
  int distance[V];
  for(int i=0; i<V; ++i) 
  {
    distance[i] = INT_MAX; // initialize all max value
    included[i] = false; // initialize all to false
  }

  // include the first node in the SPT
  distance[root] = 0;
  // keep track of nodes included so we can return early if needs be
  for(int i=0; i<V; ++i)
  {
    int u = minDistance(distance, included);
    included[u] = true;
    // traverse all adjacent nodes of u
    for(auto it=adj[u].begin(); it!=adj[u].end(); ++it)
    { 
      if(!included[*it] && distance[u] != INT_MAX && distance[u]+1 < distance[*it])
      {
        distance[*it] = distance[u]+1;
      }
    }
  }
  // print nodes and their distances from the root
  std::cout << "Dijkstra starting from: " << root << " (node : distance)\n";
  for(int i=0; i<V; ++i)
  {
    std::cout << i << " : " << distance[i] << "\n";
  }

}