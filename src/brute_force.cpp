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
        cout << "it " << i << endl << "\t";
        for(int i = 0; i < V; i++) {cout << traversed[i] << " ";}
        cout << endl;
        if(matrix[vertex][i] >= 1 && traversed[i] == 0) {
            cout << "\t\tPath btwn " << vertex << "&" << i << " exists. Trying DFS." << endl; 
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
        cout << "Calling DFS from BF starting at vertex " << i << endl;
        if(DFS(matrix, traversed, i, 1, V) == true) {hamPaths.push_back(order); cout << "\t\t\t\tHAM PATH!!!!" << endl;}
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

/*
def hamiltonians(G, vis = []):
    if not vis:
        for n in G:
            for p in hamiltonians(G, [n]):
                yield p
    else:
        dests = set(G[vis[-1]]) - set(vis)
        if not dests and len(vis) == len(G):
            yield vis
        for n in dests:
            for p in hamiltonians(G, vis + [n]):
                yield p
G = {'a' : 'bc', 'b' : 'ad', 'c' : 'b', 'd' : 'ac'}
print(list(hamiltonians(G)))
*/