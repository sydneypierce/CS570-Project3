#include "BruteForce.h"

#include <chrono>

using namespace std;

vector<vector<int>> hamPaths;

/**
* Runs a depth first search on the graph starting at the given node.
* Brute force algorithm, uses dynamic programming.
* 
* @param    graph   a Graph to run the algorithm on
* @param    vertex  the vertex from which to start the DFS
* @param    visited a vector to keep track of which nodes are already in the path
* @param    path    a vector symbolizing the current path built so far
* @param    V       the number of vertices/nodes in the graph
* @return   void 
* @see      Graph
*/
void DFS(Graph &graph, int vertex, vector<bool> &visited, vector<int> &path, int V) {
    // if all the vertices are visited, then the Hamiltonian path exists
    if (int(path.size()) == V) {
        // found a Hamiltonian path, add to list of possible solutions
        hamPaths.push_back(path);
        return;
    }
 
    // check all paths out of node 'vertex'
    for (int w: graph.adjList[vertex]) {
        // check that it hasn't been visited already
        if (!visited[w]) {
            visited[w] = true;
            path.push_back(w);
 
            // check if adding vertex w to the path leads to a full path
            DFS(graph, w, visited, path, V);
 
            // backtrack to cehck other paths
            visited[w] = false;
            path.pop_back();
        }
    }
}


/**
* Find shortest Hamiltonian path a graph.
* Brute force algorithm, uses dynamic programming.
* 
* @param    graph   a Graph to run the algorithm on
* @param    V       the number of vertices/nodes in the graph
* @return   void 
* @see      Graph
*/ 
void bruteForce(Graph &graph, int V) {
    //using namespace std::chrono;
    //auto ht1 = high_resolution_clock::now();

    // start with every node
    for (int start = 0; start < V; start++) {
        // add starting node to the path
        vector<int> path;
        path.push_back(start);
 
        // mark the start node as visited
        vector<bool> visited(V);
        visited[start] = true;
 
        DFS(graph, start, visited, path, V);
    }

    //auto ht2 = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(ht2 - ht1);
    //cout << "b time: " << duration.count() << endl;

    int weight, weightIdx;
    int min = INT_MAX;
    vector<int> minVec;
    for(int i = 0; i < int(hamPaths.size()); i++) { // curr ham path
        weight = 0;
        for(int j = 0; j < V-1; j++) { // curr index w/in ham path
            // iterate through adjList at j, find where next i is & save index
            // add to weight weightlist at j at index
            for(int k = 0; k < int(graph.adjList[hamPaths[i].at(j)].size()); k++) {
                if(graph.adjList[hamPaths[i].at(j)].at(k) == hamPaths[i].at(j+1)) weightIdx = k;
            }
            weight += graph.weightList[hamPaths[i].at(j)].at(weightIdx);
        }
        if(weight < min) {
            min = weight;
            minVec = hamPaths.at(i);
        }
    }

    cout << "Brute Force Solution: ";
    for(auto i : minVec) {
        cout << i + 1 << " ";
    }
    cout << "with weight: " << min << endl;
}