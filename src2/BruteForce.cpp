#include "BruteForce.h"

using namespace std;

vector<vector<int>> hamPaths;

void DFS(Graph &graph, int vertex, vector<bool> &visited, vector<int> &path, int V) {
    // if all the vertices are visited, then the Hamiltonian path exists
    if (int(path.size()) == V)
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
    
    /*for(auto i : hamPaths) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }*/
    int weight, weightIdx;
    int min = INT_MAX;
    vector<int> minVec;
    for(int i = 0; i < int(hamPaths.size()); i++) { //curr ham path
        weight = 0;
        for(int j = 0; j < V-1; j++) { // curr index w/in ham path
            //it through adjList at j, find where next i is & save index
            //add to weight weightlist at j at index
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
    cout << endl;
}