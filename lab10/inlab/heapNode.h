#ifndef HEAPNODE_H
#define HEAPNODE_H

#include<iostream>
using namespace std;

class heapNode{
    public:
        heapNode();
        ~heapNode();
        char val;
        int frequency;
        heapNode* rightNode;
        heapNode* leftNode;

};

#endif 