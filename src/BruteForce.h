/*
* Author: Sydney Pierce (CWID: 12052443)
* CS 570 Spring 2023
* Project 3
*/
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