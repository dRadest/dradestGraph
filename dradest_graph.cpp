#include <iostream>
#include <vector>
#include "dradest_graph.h"
using namespace std;
 
dradestGraph::dradestGraph(int x)
{
  V = x;
  adj = (vector<int>*)malloc(V * sizeof(std::vector<int>));
  std::cout << "graph constructed" << endl;

}