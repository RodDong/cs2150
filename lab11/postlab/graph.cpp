#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include "graphc.h"

using namespace std;

graph::graph(int i){
    vertex = i;
    l = new list<int*>[i];
}

void graph::addEdge(int i, int* j){
    l->push_back(j);
}

void graph::Bfs(int* i){
    bool visited[vertex];
    for(int j = 0; j<vertex; j++){
        visited[j] = false;
    }
    list<int*> queue;
    queue.push_back(i);

}