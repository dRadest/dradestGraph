<p><img src="https://raw.githubusercontent.com/dRadovan/dradestGraph/master/images/dr_graph_banner.png" title="dradestGraph" alt="dradestGraph logo" width="500"></p>
# DRad'est Graph

Undirected graph implementation using adjacency list representation with some basic functions (listed below).

## Installation

To run the code from the command line:

- cd into directory with the graph files
- run `g++ dradest_graph.cpp main.cpp -o out`
- run `./out.exe`

## Functions

#### `void addEdge(int u, int w)`
Inserts an edge between u and w.
Prints a message if the edge already exists in the graph.

#### `void printGraph()`
Prints the adjacency list representation of the graph.

#### `std::vector<int> BFS(int n)`
Performs a breadth first search *iteratively* starting from node n. Returns a vector of nodes.

#### `std::vector<int> iterativeDFS(int n)`
Performs a depth first search *iteratively* starting from node n. Returns a vector of nodes.	

#### `std::vector<int> recursiveDFS(int n)`
Performs a depth first search *recursively* starting from node n. Returns a vector of nodes.

#### `bool hasCycle()`
Uses DFS to detect a cycle in the graph. Preforms DFS on the graph. If, for every visited node *v*,
exists already visited node *u* that is not the parent of *v*, graph contains a cycle.

#### `bool containsCycle()`
Uses union by rank and path compression to detect a cycle in the graph. *Union by rank:* always attach 
smaller depth tree under the root of a deeper tree. Rank is not always equal to depth. *Path compression:* 
flatten the tree each time `find()` is called, i.e. save found root of node as its parent.

#### `std::vector<int>* primMST()` 
Performs Prim's algorithm to find minimum spanning tree. Simplified, since this is unweighted graph. 
Returns an adjcency list representation of a tree. 

> The algorithm may informally be described as performing the following steps:
>
>1. Initialize a tree with a single vertex, chosen arbitrarily from the graph.
>2. Grow the tree by one edge: of the edges that connect the tree to vertices not yet in the tree, find the minimum-weight edge, and transfer it to the tree.
>3. Repeat step 2 (until all vertices are in the tree).

source: [wikipedia](https://en.wikipedia.org/wiki/Prim%27s_algorithm)

#### `std::vector<int>* kruskalMST()`
Performs Kruskal's algorithm to find minimum spanning tree. Simplified, since this is unweighted graph.
Returns an adjacency list representation of a tree.

Algorithm:

>* create a forest F (a set of trees), where each vertex in the graph is a separate tree
>* create a set S containing all the edges in the graph
>* while S is nonempty and F is not yet spanning
>* &nbsp;&nbsp;&nbsp;&nbsp;remove an edge with minimum weight from S
>* &nbsp;&nbsp;&nbsp;&nbsp;if the removed edge connects two different trees then add it to the forest F, combining two trees into a single tree
>
> At the termination of the algorithm, the forest forms a minimum spanning forest of the graph. If the graph is connected, the forest has a single component and forms a minimum spanning tree

source: [wikipedia](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)  

#### `void dijkstraSPT(int root)`
Performs Dijkstra's algorithm to find shortest paths tree from root to all other nodes. Prints out nodes and their distances from root.

Algorithm:

>Let the node at which we are starting be called the initial node. Let the distance of node Y be the distance from the initial node to Y. Dijkstra's algorithm will assign some initial distance values and will try to improve them step by step.

>1. Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.
>2. Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes. Set the initial node as current.
>3. For the current node, consider all of its unvisited neighbors and calculate their tentative distances through the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbor B has length 2, then the distance to B through A will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, keep the current value.
>4. When we are done considering all of the unvisited neighbors of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.
>5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.
>6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

source: [wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

## Useful Links

* [cpp headers](http://www.cplusplus.com/forum/articles/10627/) article on cplusplus.com
* algolist.net [dfs](http://www.algolist.net/Algorithms/Graph/Undirected/Depth-first_search)
* geeksforgeeks [graph ds and algorithms](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
* WilliamFiset's yt video on [topological sorting](https://youtu.be/eL-KzMXSXXI)
* isocpp.org [operator overloading tutorial](https://isocpp.org/wiki/faq/operator-overloading)

## Acknowledgement

Font used for logo / banner: [Brankovic](https://www.dafont.com/brankovic.font)