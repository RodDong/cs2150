#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include "heap.h"
#include "heapNode.h"

using namespace std;


heap::heap(){
    size = 0;
    root = new heapNode();
}


heap::~heap(){
}


bool heap::isLeaf(heapNode*node){
    if(node->rightNode==NULL && node->leftNode==NULL){
        return true;
    }else{
        return false;
    }
}

void heap::treeInsert(string prefix, string character, heapNode* root){
    if(prefix.length() == 0){
        root->val = character[0];
        return;
    }
    else if(prefix[0] == '0'){
        prefix.erase(0,1);
        if(root->leftNode == NULL){
            heapNode* left = new heapNode();
            root->leftNode = left;
        }
        treeInsert(prefix, character, root->leftNode);
    }
    else if(prefix[0] == '1'){
        prefix.erase(0,1);
        if(root->rightNode == NULL){
            heapNode* right = new heapNode();
            root->rightNode = right;
        }
        treeInsert(prefix, character, root->rightNode);
    }

}

