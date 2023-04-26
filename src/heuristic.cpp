#include "Heuristic.h"

#include <chrono>

using namespace std;

/**
* Find shortest Hamiltonian path a graph.
* Heuristic algorithm based on nearest neighbor for TSP, does not always find "best" answer.
* 
* @param    graph   a Graph to run the algorithm on
* @param    V       the number of vertices/nodes in the graph
* @return   void 
* @see      Graph
*/
void heuristic(Graph &graph, int V) {
    auto m = graph.matrix;
    int minPathWeight = 99999999;
    vector<int> minPath;
    vector<int> path;
    int weight;

    //using namespace std::chrono;
    //auto ht1 = high_resolution_clock::now();
    
    for(int i = 0; i < V; i++) {    // start at all vertices once
        weight = 0;
        path.clear();
        path.push_back(i);

        while(int(path.size()) < V) { //it through neighbors of backmost path node, add shortest to path that's not already there
            vector<int> currVec = m.at(path.back());    // vector of current node
            int min = 99999999;
            for(int j = 0; j < int(currVec.size()); j++) {   // it through current node's neighbors & pick smallest not in path already
                if(currVec.at(j) != 0 && currVec.at(j) < min) {
                    if(find(path.begin(), path.end(), j) == path.end()) min = j;
                }
            }
            if(min == 99999999) break; // no possible neighbors

            path.push_back(min);    // if a path out was found, add it to the path
            weight += currVec.at(min);
        }
        if(int(path.size()) == V) {    // add path to list if path size == V
            if(weight < minPathWeight) {
                minPath = path;
                minPathWeight = weight;
            }
        }
    }

    //auto ht2 = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(ht2 - ht1);
    //cout << "h time: " << duration.count() << endl;

    if(minPath.size() == 0) {
        cout << "The heuristic either fails for this graph or there is no Hamiltonian path." << endl;
    } else {
       cout << "Heuristic solution:   ";
        for(auto v : minPath) {
            cout << v + 1 << " ";
        }
        cout << "with weight: " << minPathWeight << endl; 
    }
}