# CS570-Project3
Created By: Sydney Pierce

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#requirements">Requirements</a></li>
    <li><a href="#rHamiltonian-Path-Problem">Hamiltonian Path Problem</a></li>
    <li>
      <a href="#Heuristic-and-Brute-Force-Algorithms">Heuristic and Brute Force Algorithms</a>
      <ul>
        <li><a href="#usage-1">Usage</a></li>
        <li><a href="#features-1">Features</a></li>
        <li><a href="#conclusion-1">Conclusion</a></li>
      </ul>
    </li>
    <li>
      <a href="#Longest-Path-to-Shortest-Hamiltonian-Path-Mapping-Algorithm">Longest Path to Shortest Hamiltonian Path Mapping Algorithm</a>
      <ul>
        <li><a href="#usage-2">Usage</a></li>
        <li><a href="#features-2">Features</a></li>
        <li><a href="#conclusion-2">Conclusion</a></li>
      </ul>
    </li>
    <li>
      <a href="#Shortest-Hamiltonian-Path-to-Travelling-Salesman-Problem-Mapping-Algorithm">Shortest Hamiltonian Path to Travelling Salesman Problem Mapping Algorithm</a>
      <ul>
        <li><a href="#usage-3">Usage</a></li>
        <li><a href="#features-3">Features</a></li>
        <li><a href="#conclusion-3">Conclusion</a></li>
      </ul>
    </li>
    <li>
      <a href="#Graphs">Graphs</a>
      <ul>
        <li><a href="#graph1">Graph1</a></li>
        <li><a href="#graph2">Graph2</a></li>
        <li><a href="#graph3">Graph3</a></li>
        <li><a href="#graph4">Graph4</a></li>
      </ul>
    </li>
  </ol>
</details>

<!-- REQUIREMENTS -->
## Requirements
C++ 11 or greater

## Hamiltonian Path Problem
The Hamiltonian path problem consists of finding a path through a graph that visits each node *exactly once*. To make this decision problem into an optimization problem, I decided to try to find the *shortest* Hamiltonian path in a given graph.

<!-- HEURISTIC AND BRUTE FORCE -->
# Heuristic and Brute Force Algorithms
(main.cpp, Heuristic.cpp, BruteForce.cpp)
This project implements both a brute force and a heuristic algorithms for a Hamiltonian path on a provided graph. These algorithms perform an NP-Hard implementation of the Hamiltonian path problem that attempts to find the **shortest** Hamiltonian path. It takes as input a file representing a graph, transforms this into a user-defined graph stucture, and outputs the result of the brute force and heuristic solutions.  
The heuristic algorithm is based on the nearest neighbor heuristic for the travelling salesman problem. This idea was adapted to fit the implementation of a shortest Hamiltonian path. The nearest neighbor heuristic is an approximation algorithm, meaning that it does NOT guarantee an optimal solution.  
The brute force algorithm takes a dynamic programming approach, and runs a depth first search algorithm starting from every node. This algorithm checks all possible paths, so as long as the path exists and the graph is not too large, it will find an optimal solution.

<!-- USAGE1 -->
## Usage 1
To compile the files necessary to run the heuristic and brute force algorithms, run `make run`.  
To run **both** the heuristic and brute force algorithms, run `./a.out graph_file`.  
To run the *heuristic only*, run `./a.out graph_file h`.  
To run the *brute force only*, run `./a.out graph_file b`.  
To remove the a.out executable and any .o files, run `make clean`.

<!-- FEATURES1 -->
## Features 1
Execution of a heuristic and/or brute force algorithm on a given graph.  
Displays both the path chosen and the weight of this path.

<!-- CONCLUSION1 -->
## Conclusion 1
This project provides a comparison of a heuristic and brute force algorithm for finding a shortest Hamiltonian path. It demonstrates the advantages and disadvantages of each approach by showing that the brute force algorithm is more "accurate", but the heuristic can work with much larger graphs.


<!-- LONGEST -->
# Longest Path to Shortest Hamiltonian Path Mapping Algorithm
(longestToHam.cpp)
This project takes as input a file representing a graph for a longest path problem, and then transforms the graph by the mapping process described in **report.pdf**. It outputs this tranformed graph into a separate file named **longToHam.dat**; it does NOT change the input file. When this new file is given as input to **main.cpp**, it will result in the answer to the longest path problem for the original graph. (The answer shown will be negative; the actual answer is the absoulte value of the output.) This demonstrates a mapping from longest path to Hamiltonian path.

<!-- USAGE2 -->
## Usage 2
To compile the files necessary to run the longest path to Hamiltonian path mapping algorithm, run `make from`.  
To run the algorithm, run `./a.out graph_file`.  
To test the new graph, run `make run` then `./a.out longToHam.dat`.  
To remove the a.out executable and any .o files, run `make clean`.

<!-- FEATURES2 -->
## Features 2
Creates a new .dat file with the input graph data altered by the mapping algorithm (made to be an input file for a shortest Hamiltonian path algorithm).

<!-- CONCLUSION2 -->
## Conclusion 2
This project provides a mapping from the longest path problem to the shortest path optimization of the Hamiltonian path problem. 


<!-- TSP -->
# Shortest Hamiltonian Path to Travelling Salesman Problem Mapping Algorithm
(hamToTSP.cpp)
This project takes as input a file representing a graph for a Hamiltonian path problem, and then transoforms the graph by the mapping process described in **report.pdf**. It outputs this tranformed graph into a separate file named **lhamToTSP.dat**; it does NOT change the input file. When this new file is given as input to a travelling salesman algorithm, it will result in the answer to the Hamiltonian path problem for the original graph.

<!-- USAGE3 -->
## Usage 3
To compile the files necessary to run the longest path to Hamiltonian path mapping algorithm, run `make to`.  
To run the algorithm, run `./a.out graph_file`.  
This file can be run on a travelling salesman algorithm to answer the Hamiltonian path problem.
To remove the a.out executable and any .o files, run `make clean`.  

<!-- FEATURES3 -->
## Features 3
Creates a new .dat file with the input graph data altered by the mapping algorithm (made to be an input file for a travelling salesman algorithm).

<!-- CONCLUSION3 -->
## Conclusion 3
This project provides a mapping from the shortest path optimization of the Hamiltonian path problem to the travelling salesman problem. 

<!-- GRAPHS -->
# Graphs
## Graph1
Graph 1 is a simple, directed graph with 10 nodes. Both my heuristic and brute force get the same weight for this graph, although they come up with different paths because algorithms traverse the graphs in different orders.  

![G1](/imgs/Graph1.PNG?raw=true "G1")  
![G1 Cert](/imgs/Graph1_cert.PNG?raw=true "G1 Cert")  

## Graph2
Graph 2 is a directed graph with 6 nodes. My heuristic does not get the optimal answer for this graph, but it is only off by 1. This is expected, as the nearest neighbor heuristic is not guaranteed to get the "correct" answer every time.  

![G2](/imgs/Graph2.PNG?raw=true "G2")  
![G2 Cert](/imgs/Graph2_cert.PNG?raw=true "G2 Cert")  

## Graph3
Graph 3 is a small directed graph. My heuristic does not work *at all* on this one.  

![G3](/imgs/Graph3.PNG?raw=true "G3")  
![G3 Cert](/imgs/Graph3_cert.PNG?raw=true "G3 Cert")  

## Graph4
Graph 4 is a large graph with 64 nodes and 126 edges. My heuristic generates the optimal answer, but my brute force cannot find any answer within a reasonable amount of time.  

![G4](/imgs/Graph4.PNG?raw=true "G4")  
![G4 Cert](/imgs/Graph4_cert.PNG?raw=true "G4 Cert")  
