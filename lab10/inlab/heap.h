#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include<unordered_map>
#include "heapNode.h"

using namespace std;
class heap{
    public:
        heap();
        ~heap();
        int size;
        heapNode* root;
        void insert(heapNode* node);
        heapNode* deleteMin();
        bool isLeaf(heapNode* node);
        void printTree(heapNode* root, string s);
        void treeInsert(string prefix, string character, heapNode* root);

};

#endif
