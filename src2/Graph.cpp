#include "Graph.h"

using namespace std;
 
Graph::Graph(vector<Edge> &edges, int n)
{
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
        //adjList[dest].push_back(src);
    }
}