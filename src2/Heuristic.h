#ifndef _HEURISTIC_H_
#define _HEURISTIC_H_

#include "Edge.h"
#include "Graph.h"
#include <climits>
#include <iostream>
#include <vector>

int checkPath(int **mtx);

void heuristic(Graph &graph, int V);

#endif