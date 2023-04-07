// brute force algorithm for Hamiltonian path
// process: Given an adjacency matrix, iterate through the vertices & try all DFS paths for each.
// (cont'd) If a DFS has to revisist a node, terminate it. Once a Hamiltonian path is found, return it.

#include "brute_force.h"

using namespace std;

vector<int> order;

bool DFS(int **matrix, int traversed[], int vertex, int numTraversed, int V) {
    //change to ret a vec w vertices added in order if true, null if false
    //order.push_back(vertex + 1);
    if(numTraversed == V) {
        order.push_back(vertex + 1);
        return true;
    } 

    for(int i = 0; i < V; i++) {
        if(matrix[vertex][i] >= 1 && traversed[i] == 0) {
            traversed[i] = 1;
            if(DFS(matrix, traversed, i, numTraversed + 1, V) == true) {
                order.push_back(vertex + 1);
                return true; 
            } 
            traversed[i] = 0;
        }
    }
    return false;
}

vector<int> bruteForce(int **matrix, const int V) {
    //change to ret a vec with vertices in order of traversal
    //tracks if each vertex has been travelled to yet
    int traversed[V] = {0};
    vector<vector<int>> hamPaths;

    for(int i = 0; i < V; i++) {
        traversed[i] = 1;
        if(DFS(matrix, traversed, i, 1, V) == true) hamPaths.push_back(order);
        order.clear();
        traversed[i] = 0;
    }

    int weight;
    int min = INT_MAX;
    vector<int> minVec;
    for(auto v : hamPaths) {
        weight = 0;
        for(int i = V-1; i > 0; i--) {
            weight += matrix[v.at(i) - 1][v.at(i - 1) - 1];
        }
        if(weight <= min) {
           minVec = v; 
           min = weight;
        } 
    }
    return minVec;
}