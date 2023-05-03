/*
* Author: Sydney Pierce (CWID: 12052443)
* CS 570 Spring 2023
* Project 3
*/
#include "Edge.h"
using namespace std;

/**
* Constructor for a Graph instance.
* 
* @param    a   source node
* @param    b   destination node
* @param    c   edge weight from a to b
*/
Edge::Edge(int a, int b, int c) {
    src = a;
    dest = b;
    weight = c;
}