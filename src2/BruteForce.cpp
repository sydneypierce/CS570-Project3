#include "BruteForce.h"

using namespace std;

vector<vector<int>> hamPaths;

void DFS(Graph &graph, int vertex, vector<bool> &visited, vector<int> &path, int V) {
    // if all the vertices are visited, then the Hamiltonian path exists
    if (path.size() == V)
    {
        // print the Hamiltonian path
        hamPaths.push_back(path);
        return;
    }
 
    // Check if every edge starting from vertex `v` leads to a solution or not
    for (int w: graph.adjList[vertex])
    {
        // process only unvisited vertices as the Hamiltonian
        // path visit each vertex exactly once
        if (!visited[w])
        {
            visited[w] = true;
            path.push_back(w);
 
            // check if adding vertex `w` to the path leads to the solution or not
            DFS(graph, w, visited, path, V);
 
            // backtrack
            visited[w] = false;
            path.pop_back();
        }
    }
}
 
void bruteForce(Graph &graph, int V)
{
    // start with every node
    for (int start = 0; start < V; start++)
    {
        // add starting node to the path
        vector<int> path;
        path.push_back(start);
 
        // mark the start node as visited
        vector<bool> visited(V);
        visited[start] = true;
 
        DFS(graph, start, visited, path, V);
    }
    

    /*int min = INT_MAX;
    vector<int> minVec;
    int weight, weightIdx;
    for(auto i : hamPaths) {
        weight = 0;
        for(int j = 0; j < V; j++) {
            //cout << j + 1 << " ";
            for(int k = 0 : graph.adjList) {
                if(i.at(j+1) == k)
                weight += (i.at(j))
            }
        }
        cout << endl;
    }*/
}