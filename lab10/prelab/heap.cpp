#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include "heap.h"
#include "heapNode.h"

using namespace std;


heap::heap(){
    size = 0;
    heapNode* root = new heapNode();
    v.push_back(root);
}

heap::heap(vector<heapNode*> v){
    size = v.size();
    root = v[0];
}

heap::~heap(){
}

void heap::insert(heapNode* node){
    v.push_back(node);
    percolateUp(++size);
}

void heap::percolateUp(int index){
    heapNode* node = v[index];
    int f = v[index]->frequency;
    for(; (index>1)&&(f<v[index/2]->frequency);index/=2){
        v[index] = v[index/2];
    }
    v[index] = node;
}

heapNode* heap::deleteMin(){
    if(size == 0){
        throw "deleteMin() called on empty heap";
    }

    heapNode* node = v[1];
    v[1] = v[size--];
    v.pop_back();
    percolateDown(1);
    return node;
}

void heap::percolateDown(int index){
    heapNode* node = v[index];
    while(index*2 <= size){
        int child = index*2;
        if((child+1 <= size)&&(v[child+1]->frequency<v[child]->frequency)){
            child++;
        }
        if(node->frequency>v[child]->frequency){
            v[index] = v[child];
            index = child;
        }else{
            break;
        }

        v[index] = node;
    }
}

void heap::printHeap(){
    for (int i = 1; i<size+1; i++){
        cout << "value: " << v[i]->val << " frequency: "<<v[i]->frequency<<endl;
    }
}

void heap::compression(){
    while(size>1){
        heapNode* left = deleteMin();
        heapNode* right = deleteMin();
        heapNode* r = new heapNode('?',left->frequency+right->frequency);
        r->leftNode = left;
        r->rightNode = right;
        if(right->rightNode!=NULL&&left->rightNode==NULL&&right->frequency==left->frequency){
            r->leftNode = right;
            r->rightNode = left;
        }else{
            r->leftNode = left;
            r->rightNode = right;
        }
        insert(r);
    }
}

void heap::printTree(heapNode* root){
    cout<<root->leftNode->val<<endl;
}

bool heap::isLeaf(heapNode*node){
    if(node->rightNode==NULL && node->leftNode==NULL){
        return true;
    }else{
        return false;
    }
}


void heap::prefixCode(heapNode* root, string s){
    if(root->leftNode!=NULL){
        s.append("0");
        prefixCode(root->leftNode, s);
        s.pop_back();
    }
    if(root->rightNode!=NULL){
        s.append("1");
        prefixCode(root->rightNode, s);
        s.pop_back();
    }
    if(isLeaf(root)){
        string str;
        str.push_back(root->val);
        if(root->val == ' '){
            str = "space";
        }
        map[str] = s;
        s.pop_back();
    }
}

