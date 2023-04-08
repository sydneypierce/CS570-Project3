#include "Heuristic.h"

using namespace std;

// checks the normal path for 0 elements
// returns column of 0 index, -1 if none
int checkPath(vector<vector<int>> mtx, int V) {
    for(int i = 1; i < V; i++) {
            if(mtx[i][i+1] == 0) return i+1;
    }
    return -1;
}

void heuristic(Graph &graph, int V) {
    auto m = graph.matrix;
    int zeroIdx = -1;

    for(int i = 0; i < V+1; i++) {
        for(int j = 0; j < V+1; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    zeroIdx = checkPath(m, V);

    if(zeroIdx == -1) { // if no 0 elements in normal path, print order
        cout << "Heuristic Solution: ";
        for(int i = 1; i < V+1; i++) {cout << m[0][i] << " ";}
        cout << endl;
        return;
    }
    cout << "normal path needs to be fixed on col " << zeroIdx << endl;
    
}