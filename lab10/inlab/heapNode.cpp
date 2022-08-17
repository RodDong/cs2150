#include <iostream>
#include <vector>
#include "heapNode.h"

using namespace std;

heapNode::heapNode(){
    val = '?';
    frequency = 0;
    rightNode = NULL;
    leftNode = NULL;
}


heapNode::~heapNode(){
        // delete rightNode;
        // delete leftNode;
        // rightNode = NULL;
        // leftNode = NULL;
}