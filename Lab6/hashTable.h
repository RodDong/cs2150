#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <list>
#include <string>

using namespace std;

class hashTable
{
public:
    vector<list<string>> v;
    int elementCount;
    hashTable(int i);
    int hash(string s);
    void insert(string s);
    bool check(string s);
    int minlength();
    int maxlength();
    int maxHash();
    int minHash();
    int length();
};

#endif