/*
* Author: Sydney Pierce (CWID: 12052443)
* CS 570 Spring 2023
* Project 3
*/
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
    std::vector<std::vector<int>> matrix;
 
    // Constructor
    Graph(std::vector<Edge> &edges, int **mtx, int n);

};

#endif