#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    ifstream file(argv[1], ifstream::binary);

    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    string s1, s2;
    vector<string> elements;
    map<string, int> map;
    while(!file.eof()){
        file >> s1;
        file >> s2;
        if(s1 == "0" && s2 == "0"){
            break;
        }
        elements.push_back(s1);
        elements.push_back(s2);
    }

    for(int i = 0; i<elements.size(); i++){
        map[elements[i]] = i;
    }
    
    graph g(elements.size());

    file.clear();
    file.seekg(0);

    while(!file.eof()){
        file >> s1;
        file >> s2;
        if(s1 == "0" && s2 == "0"){
            break;
        }
        g.addEdge(s1, s2, map);
    }

    g.print();

    file.close();
}