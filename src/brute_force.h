#ifndef _BRUTE_FORCE_H_
#define _BRUTE_FORCE_H_

#include <string>
#include <iostream>
#include <vector>
#include <climits>

bool DFS(int **matrix, int traversed[], int vertex, int numTraversed, int V);

//std::string bruteForce(int **matrix, const int V);
std::vector<int> bruteForce(int **matrix, const int V);

#endif