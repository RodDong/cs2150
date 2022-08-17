#ifndef HEAPNODE_H
#define HEAPNODE_H

#include<iostream>
#include<vector>
using namespace std;

class heapNode{
    public:
        heapNode();
        heapNode(char c, int frequency);
        ~heapNode();
        char val;
        int frequency;
        int prefix;
        heapNode* rightNode;
        heapNode* leftNode;

};

#endif 