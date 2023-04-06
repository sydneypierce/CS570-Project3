#include "brute_force.h"
#include "heuristic.h"

#include <algorithm>
#include <cstring>
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

    // create matrix
    int **matrix = new int*[V];
    for(int i = 0; i < V; i++) {
        matrix[i] = new int[V];
    }
    // initialize with zeroes
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }

    // while have not reached '$', read from file and populate the adjacency matrix
    vector<int> spaceVec;
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

        // if the value is 0 -> assign it as z
        // else, check if z is less than the current value
        if(matrix[x-1][y-1] == 0) {
            matrix[x-1][y-1] = z;
        } else if(z < matrix[x-1][y-1]) {
            matrix[x-1][y-1] = z;
        } 
    }
    graphFile.close();

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //call heuristic and/or brute force algorithms based on flags
    string result;
    vector<int> res;
    if(hFlag == 1) {
        // call heuristic here
        result = heuristic(matrix, V);
        cout << result << endl;
    }

    if(bFlag == 1) {
        // call brute force here
        //result = bruteForce(matrix, V);
        //cout << result << endl;
        res = bruteForce(matrix, V);
        for(auto x : res) {
            cout << x << "->";
        }
        cout << endl;
    }

    return 0;
}