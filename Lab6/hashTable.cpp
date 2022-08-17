#include <iostream>
#include "hashTable.h"
using namespace std;

hashTable::hashTable(int i)
{
    elementCount = i;
    list<string> l;
    for (int i = 0; i < elementCount; i++)
    {
        v.push_back(l);
    }
}

int hashTable::hash(string s)
{
    int p = 54;
    unsigned int hashValue = 0;
    int power = 1;
    for (int i = 0; i < s.length(); i++)
    {
        hashValue = (hashValue + (s[i]-'a'+1) * power);
        power = power * p;
    }
    return hashValue%elementCount;
}

void hashTable::insert(string s)
{
    if (s.length() >= 3)
    {
        int i = hash(s);
        v[i].push_back(s);
    }
}

bool hashTable::check(string s)
{
    if (v[hash(s)].front() == s)
    {
        return true;
    }
    else
    {
        for (list<string>::iterator i = v[hash(s)].begin(); i != v[hash(s)].end(); i++)
        {
            if (*i == s)
            {
                return true;
            }
        }
    }
    return false;
}

int hashTable::minlength(){
    int min = 20;
    for(int i = 0; i<v.size(); i++){
        if(v[i].size()<min){
            min = v[i].size();
        }
    }
    return min;
}

int hashTable::maxlength(){
    int max = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i].size()>max){
            max = v[i].size();
        }
    }
    return max;
}

int hashTable::maxHash(){
    int max = 0;
    for(int i = 0; i<v.size(); i++){
        for (list<string>::iterator j = v[i].begin(); j != v[i].end(); ++j)
        {
            if(hash(*j)>max){
                max = hash(*j);
            }
        }
    }
    return max;
}

int hashTable::minHash(){
    int min = 1000;
    for(int i = 0; i<v.size(); i++){
        for (list<string>::iterator j = v[i].begin(); j != v[i].end(); ++j)
        {
            if(hash(*j)<min){
                min = hash(*j);
            }
        }
    }
    return min;
}

int hashTable::length(){
    int result = 0;
    for(int i = 0; i<v.size(); i++){
        result+=v[i].size();
    }
    return result;
}