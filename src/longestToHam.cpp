/*
* Author: Sydney Pierce (CWID: 12052443)
* CS 570 Spring 2023
* Project 3
*/

#include "Graph.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
    // error check usage
    if (argc != 2) {
        cout << "Usage: ./a.out graph_file" << endl;
        return 1;
	}

    // open file, error check
    fstream graphFile;
    graphFile.open(argv[1]);
    if(!graphFile) {
        cout << argv[1] << " not available" << endl;
        return 1;
    }

    // get first line (name)
    string currLine;
    getline(graphFile, currLine);

    // get second line (# vertices)
    int V = 0;
    getline(graphFile, currLine);
    V = stoi(currLine);

    // open output file
    fstream longToHamFile;
    longToHamFile.open("longToHam.dat", ios::out);

    longToHamFile << "Hamiltonian Path" << endl;
    longToHamFile << V << endl;

    // while have not reached '$', read from file and populate the edge vector & matrix
    vector<int> spaceVec;
    while(getline(graphFile, currLine)) {
        if(currLine.find("$") != string::npos) break;
        spaceVec.clear();

        // remove carriage return to avoid parsing issues
        currLine.erase(remove(currLine.begin(), currLine.end(), '\r'), currLine.end());

        // find positions of spaces, parse vertex numbers out of string and add edge to matrix (don't need weight)
        for(size_t i = 0; i < currLine.length(); i++) {
            if(currLine[i] == ' ') spaceVec.push_back(i);
        }

        // write src & dest nodes as is
        longToHamFile << stoi(currLine.substr(0, spaceVec.at(0))) << " " << stoi(currLine.substr(spaceVec.at(0) + 1, (spaceVec.at(1) - spaceVec.at(0) - 1))) << " ";
        // write weight as negative
        longToHamFile << -stoi(currLine.substr(spaceVec.at(1) + 1)) << endl;
    }
    longToHamFile << "$" << endl;
    
    graphFile.close();
    longToHamFile.close();

    return 0;
}