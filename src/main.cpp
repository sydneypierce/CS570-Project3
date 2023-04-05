#include "brute_force.h"
#include "heuristic.h"

#include <iostream>
#include <fstream>


using namespace std;

int main (int argc, char *argv[]) {
    // error check usage
    if (argc!=2) {
		cout << "Usage: ./a.out graph_file" << endl;
		return 1;
	}

    // open file, error check
    fstream = graphFile;
    graphFile.open(argv[1]);
    if(!graphFile) {
        cout << argv[1] << " not available" << endl;
        return 1;
    }

    // get first line (# vertices)
    string currLine;
    int V = 0;
    V = getline(graphFile, currLine);

    int matrix[V][V];
    // while have not reached '$', read from file and populate the adjacency matrix
    while(!(getline(graphFile, currLine).find("$"))) {
        cout << currLine << endl;
    }

    // close file
    graphFile.close();

    return 0;
}