#include "Graph.h"

using namespace std;
 
Graph::Graph(vector<Edge> &edges, int **mtx, int n)
{
    // populate matrix
    matrix.resize(n + 1);
    for(int i = 0; i < n + 1; i++) {matrix[0].push_back(i);}
    for(int i = 1; i < n + 1; i++) {
        matrix[i].resize(n + 1);
        matrix[i][0] = i;   // makes first col = row #
        for(int j = 1; j < n + 1; j++) {
            matrix[i][j] = mtx[i-1][j-1];
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