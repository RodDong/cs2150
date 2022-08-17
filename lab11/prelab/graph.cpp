#include "graph.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

graph::graph(int i){
    vertex = i;
    v = new vector<int>[vertex];
}

void graph::addEdge(string str1, string str2, map<string, int> map){
    int i = map[str1];
    int j = map[str2];
    m[i] = str1;
    m[j] = str2;
    v[i].push_back(j);
}

void graph::sort(int i, vector<int> &vec, bool visited[]){
    visited[i] = true;
    vector<int>::iterator itr;
    for(itr =v[i].begin(); itr!=v[i].end(); ++itr){
        if(!visited[*itr]){
            sort(*itr, vec, visited);
        }
    }
    vec.push_back(i);
}

void graph::print(){
    vector<int> vec;
    bool* visited = new bool[vertex];
    for(int i = 0; i<vertex; i++){
        visited[i] = false;
    }
    for(int i = 0; i<vertex; i++){
        if(visited[i] == false){
            sort(i, vec, visited);
        }
    }
    for(int i = vec.size()-1; i>0; i--){
        if(m[vec[i]]!=""){
            cout<<m[vec[i]]<<" ";
        }
    }
}