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

heapNode::heapNode(char c, int freq){
    val = c;
    frequency = freq;
    rightNode = NULL;
    leftNode = NULL;
}

heapNode::~heapNode(){
    if(rightNode!=NULL){
        delete rightNode;
    }
    if(leftNode!=NULL){
        delete leftNode;
    }
}