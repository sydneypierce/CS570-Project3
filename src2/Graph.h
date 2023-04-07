#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "Edge.h"
#include <iostream>
#include <vector>

class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    std::vector<std::vector<int>> adjList;
    std::vector<std::vector<int>> weightList;
 
    // Constructor
    Graph(std::vector<Edge> &edges, int n);

};

#endif