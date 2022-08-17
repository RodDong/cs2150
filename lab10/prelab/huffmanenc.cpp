#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include<math.h>
#include <unordered_map>
#include<algorithm>
#include "heap.h"

using namespace std;

bool compare(heapNode* h1, heapNode* h2){
    if (h1->frequency < h2->frequency) {
        return true;
    } else if (h1->frequency > h2->frequency) {
        return false;
    }else{
        int i1, i2;
        i1 = h1->val;
        i2 = h2->val;
        if(i1 < i2){
            return true;
        }else if(i1 > i2){
            return false;
        }else{
            return false;
        }
    }
}

int main(int argc, char** argv){
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }
    string txt;
    char g;
    vector<heapNode*> heapNodes;
    int hash;
    heap h = heap();
    for(int i = 0; i<108; i++){
        heapNodes.push_back(NULL);
    }
    while (file.get(g)) {
        if(g!='\n'){
            txt.push_back(g);
        }
        hash = int(g)-32;
        heapNode* temp = new heapNode(g, 1);
        if(heapNodes[hash]==NULL){
            heapNodes[hash] = temp;
        }else{
            heapNodes[hash]->frequency+=1;
        }
    }

    vector<heapNode*> sortedHeap;
    for(int i = 0; i<heapNodes.size(); i++){
        if(heapNodes[i]!=NULL){
            sortedHeap.push_back(heapNodes[i]);
        }
    }

    sort(sortedHeap.begin(), sortedHeap.end(), compare);
    
    for(int i = 0; i<sortedHeap.size(); i++){
        h.insert(sortedHeap[i]);
    }
    h.compression();
    string s = "";
    h.prefixCode(h.v[1], s);
    string str, prefix;
    unordered_map<string, string>::iterator itr = h.map.begin();
    while(itr != h.map.end()){
        str = itr->first;
        prefix = itr->second;
        cout<<str<<"  "<<prefix<<endl;
        itr++;
    }
    
    cout << "----------------------------------------" << endl;
    file.clear();
    file.seekg(0);
    int counter = 0;
    string encoded;
    while (file.get(g)) {
        string s = "";
        if(g == ' '){
            s+="space";
        }else{
            s.push_back(g);
        }
        encoded+=(h.map[s]);
        cout<<h.map[s]<<" ";
        counter++;
    }
    cout<<endl;
    cout << "----------------------------------------" << endl;
    double ratio = double(txt.length()*8)/double(encoded.length());
    double cost = double(encoded.length())/double(txt.length());
    cout<<"There are a total of "<<counter-1<<" symbols that are encoded."<<endl;
    cout<<"There are "<<sortedHeap.size()<<" distinct symbols used."<<endl;
    cout<<"There were "<<txt.length()*8<<" bits in the original file."<<endl;
    cout<<"There were "<<encoded.length()<<" bits in the compressed file."<<endl;
    cout<<"This gives a compression ratio of "<<ratio<<endl;
    cout<<"The cost of the Huffman tree is "<<cost<<" bits per character."<<endl;
    file.close();
    return 0;
}