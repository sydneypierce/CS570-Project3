/*
* Author: Sydney Pierce (CWID: 12052443)
* CS 570 Spring 2023
* Project 3
*/
#include "Graph.h"

using namespace std;

/**
* Constructor for a Graph instance.
* 
* @param    edges   vector of edges in the graph
* @param    mtx     adjacency matrix representing the graph
* @param    n       the number of vertices/nodes in the graph
* @see      Edge
*/ 
Graph::Graph(vector<Edge> &edges, int **mtx, int n)
{
    // populate matrix
    matrix.resize(n);
    for(int i = 0; i < n; i++) {
        matrix[i].resize(n);
        for(int j = 0; j < n; j++) {
            matrix[i][j] = mtx[i][j];
        }
    }

    // resize the vector to hold `n` elements of type `vector<int>`
    adjList.resize(n);
    weightList.resize(n);
    // add edges to the undirected graph
    for (Edge edge: edges)
    {
        int src = edge.src;
        int dest = edge.dest;
        int w = edge.weight;

        adjList[src].push_back(dest);
        weightList[src].push_back(w);
    }    
}