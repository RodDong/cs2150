/** @brief Creates a topo graph and print the graph after sorting it topologically
 *  @class Class of the topo graph class
 *  @author Rod Dong
 *  @date 2021 11/30
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

class graph{
    public:
/**
 * @param i size of the graph
 * @return voi
 */
    graph(int i);
    int vertex;
    vector<int>* v;
    map<int, string> m;
/**
 * @param str1 first string of the edge
 * @param str2 second string of the edge
 * @param map map that holds the strings that points to different integers
 * @return void
 */
    void addEdge(string str1, string str2, map<string, int> map);
/**
 * @param i size of the vistied[] array
 * @param vector vector that holds the sorted strings by their directed ints
 * @param visited array that holds the bool info of whether the node has been visited
 * @return voi
 */
    void sort(int i, vector<int> &vector, bool visited[]);
    void print();
};

#endif