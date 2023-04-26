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

    fstream tspFile;
    tspFile.open("hamPathToTSP.dat", ios::out);

    tspFile << "Travelling Salesman" << endl;
    tspFile << V + 1 << endl;   // add 1 to account for new node

    // while have not reached '$', read from in file and write to out file
    while(getline(graphFile, currLine)) {
        if(currLine.find("$") != string::npos) break;
        tspFile << currLine;
    }
    graphFile.close();

    // create extra node that goes to all other nodes
    int newNode = V + 1;
    for(int i = 1; i < newNode; i++) {
        tspFile << newNode << " " << i << " " << 1 << endl;
        tspFile << i << " " << newNode << " " << 1 << endl;
    }

    tspFile << "$" << endl; // end the file
    tspFile.close();

    return 0;
}