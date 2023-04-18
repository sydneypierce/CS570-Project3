#ifndef _BRUTE_FORCE_H_
#define _BRUTE_FORCE_H_

#include "Edge.h"
#include "Graph.h"
#include <climits>
#include <iostream>
#include <vector>

void DFS(Graph &graph, int vertex, std::vector<bool> &visited, std::vector<int> &path, int V);

void bruteForce(Graph &graph, int V);

#endif