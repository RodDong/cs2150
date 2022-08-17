#include "heapNode.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;


int main (int argc, char** argv) {
    
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    
    ifstream file(argv[1], ifstream::binary);

    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    heap h;

    while (true) {
        string character, prefix;
        file >> character;

        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        if (character == "space") {
            character = " ";
        }

        file >> prefix;
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
        h.treeInsert(prefix, character, h.root);
    }

    stringstream sstm;
    while (true) {
        string bits;
        file >> bits;
        if (bits[0] == '-') {
            break;
        }
        sstm << bits;
    }
    heapNode* node = new heapNode();
    node = h.root;
    string allbits = sstm.str();
    string allbits2 = allbits;
    while(allbits.length()>0){
        if(allbits[0] == '0'&&node->leftNode!=NULL){
            allbits.erase(0,1);
            node = node->leftNode;
        }
        if(allbits[0] == '1'&&node->rightNode!=NULL){
            allbits.erase(0,1);
            node = node->rightNode;
        }
        if(node->rightNode == NULL && node->leftNode == NULL){
            cout<<node->val;
            node = h.root;
        }
    }
    cout<<endl;
    // cout << "All the bits: " << allbits2 << endl;
    file.close();

    return 0;
}