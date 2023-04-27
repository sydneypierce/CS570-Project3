# CS570-Project3
Created By: Sydney Pierce


# Heuristic and Brute Force Algorithms (main.cpp, Heuristic.cpp, BruteForce.cpp)
This project implements both a brute force and a heuristic algorithms for a Hamiltonian path on a provided graph. These algorithms perform an NP-Hard implementation of the Hamiltonian path problem that attempts to find the **shortest** Hamiltonian path. It takes as input a file representing a graph, transforms this into a user-defined graph stucture, and outputs the result of the brute force and heuristic solutions.

## Requirements
Python 3.x
Tkinter (should be included in standard Python distribution)
# Usage
To run the visualization, open the fibonacci_heap.py file in a Python IDE and click the "run" button. This will launch the Tkinter GUI, which provides a run buttons for displaying the Fibonacci heap. The visualization updates in real-time as you perform operations, allowing you to see the effects of each operation on the structure of the heap.

## Features
Real-time visualization of Fibonacci heap structure
Step-by-step visualization of basic operations (insert, extract min, and decrease key)
Interactive GUI with buttons for running animation

## Conclusion
The Fibonacci heap visualization with Tkinter is a valuable tool for those interested in learning about this data structure and its operations. The real-time visualization provides a clear and interactive way to understand the behavior of the heap, making it a valuable resource for both students and professionals alike.


# Longest Path to Shortest Hamiltonian Path Mapping Algorithm (longestToHam.cpp)
This project takes as input a file representing a graph for a longest path problem, and then transoforms the graph by the mapping process described in **report.pdf**. It outputs this tranformed graph into a separate file named **longToHam.dat**; it does NOT change the input file. When this new file is given as input to **main.cpp**, it will result in the answer to the longest path problem for the original graph.


# Shortest Hamiltonian Path to Travelling Salesman Problem Mapping Algorithm (hamToTSP.cpp)
This project takes as input a file representing a graph for a Hamiltonian path problem, and then transoforms the graph by the mapping process described in **report.pdf**. It outputs this tranformed graph into a separate file named **lhamToTSP.dat**; it does NOT change the input file. When this new file is given as input to a travelling salesman algorithm, it will result in the answer to the Hamiltonian path problem for the original graph.
