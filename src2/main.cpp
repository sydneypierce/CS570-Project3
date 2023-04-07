#include "BruteForce.h"
#include "Edge.h"
#include "Graph.h"

#include <algorithm>
//#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
    // error check usage
    if (argc != 2) {
        if (argc < 2 || argc > 3) {
            cout << "Usage: ./a.out graph_file <optional: b or h>" << endl;
            return 1;
        } else if(!(argc == 3 && (strcmp(argv[2], "h") == 0 || strcmp(argv[2], "b")) == 0)) { // if argc == 3, check if b or h
            cout << "Usage: ./a.out graph_file <optional: b or h>" << endl;
            return 1;
        }
	}

    //flags for brute force and heuristic, default set, clear other if one is indicated in command line
    int bFlag, hFlag;
    bFlag = hFlag = 1;

    if(argc == 3) {
        if(strcmp(argv[2], "b") == 0) hFlag = 0;
        if(strcmp(argv[2], "h") == 0) bFlag = 0;
    }

    // open file, error check
    fstream graphFile;
    graphFile.open(argv[1]);
    if(!graphFile) {
        cout << argv[1] << " not available" << endl;
        return 1;
    }

    // get first line (# vertices)
    string currLine;
    int V = 0;
    getline(graphFile, currLine);
    V = stoi(currLine);

    // while have not reached '$', read from file and populate the adjacency matrix
    vector<int> spaceVec;
    vector<Edge> edges;
    int x, y, z;
    while(getline(graphFile, currLine)) {
        if(currLine.find("$") != string::npos) break;

        // remove carriage return to avoid parsing issues
        currLine.erase(remove(currLine.begin(), currLine.end(), '\r'), currLine.end());

        // find positions of spaces, parse vertex numbers out of string and add edge to matrix (don't need weight)
        for(size_t i = 0; i < currLine.length(); i++) {
            if(currLine[i] == ' ') spaceVec.push_back(i);
        }
        x = stoi(currLine.substr(0, spaceVec.at(0)));
        y = stoi(currLine.substr(spaceVec.at(0) + 1, (spaceVec.at(1) - spaceVec.at(0) - 1)));
        z = stoi(currLine.substr(spaceVec.at(1) + 1));

        edges.push_back({x-1, y-1, z});
    }
    graphFile.close();

    Graph g(edges, V);
    bruteForce(g, V);

    //call heuristic and/or brute force algorithms based on flags
    string result;
    vector<int> res;
    if(hFlag == 1) {
        // call heuristic here
    }

    if(bFlag == 1) {
        // call brute force here
        //returns backwards vec, print switched
    }

    return 0;
}

/*#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);
 
        // add edges to the undirected graph
        for (Edge edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
 
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};
 
// Utility function to print a path
void printPath(vector<int> const &path)
{
    for (int i: path) {
        cout << i << ' ';
    }
    cout << endl;
}
 
void hamiltonianPaths(Graph const &graph, int v, vector<bool> &visited,
                    vector<int> &path, int n)
{
    // if all the vertices are visited, then the Hamiltonian path exists
    if (path.size() == n)
    {
        // print the Hamiltonian path
        printPath(path);
        return;
    }
 
    // Check if every edge starting from vertex `v` leads to a solution or not
    for (int w: graph.adjList[v])
    {
        // process only unvisited vertices as the Hamiltonian
        // path visit each vertex exactly once
        if (!visited[w])
        {
            visited[w] = true;
            path.push_back(w);
 
            // check if adding vertex `w` to the path leads to the solution or not
            hamiltonianPaths(graph, w, visited, path, n);
 
            // backtrack
            visited[w] = false;
            path.pop_back();
        }
    }
}
 
void findHamiltonianPaths(Graph const &graph, int n)
{
    // start with every node
    for (int start = 0; start < n; start++)
    {
        // add starting node to the path
        vector<int> path;
        path.push_back(start);
 
        // mark the start node as visited
        vector<bool> visited(n);
        visited[start] = true;
 
        hamiltonianPaths(graph, start, visited, path, n);
    }
}
 
int main()
{
    // consider a complete graph having 4 vertices
    vector<Edge> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
    };
 
    // total number of nodes in the graph (labelled from 0 to 3)
    int n = 4;
 
    // build a graph from the given edges
    Graph graph(edges, n);
 
    findHamiltonianPaths(graph, n);
 
    return 0;
}*/