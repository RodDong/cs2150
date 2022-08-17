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
        heap(vector<heapNode*> v);
        ~heap();
        vector<heapNode*> v;
        int size;
        heapNode* root;
        void insert(heapNode* node);
        heapNode* deleteMin();
        void percolateUp(int index);
        void percolateDown(int index);
        void printHeap();
        void prefixCode(heapNode* root, string s);
        void compression();
        bool isLeaf(heapNode* node);
        void printTree(heapNode* root);
        unordered_map <string, string>map;

};

#endif
