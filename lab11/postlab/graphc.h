#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

class graph{
    public:
        int vertex;
        list<int*>* l;
        graph(int i);
        void addEdge(int i, int* j);
        void Bfs(int* i);
};

#endif