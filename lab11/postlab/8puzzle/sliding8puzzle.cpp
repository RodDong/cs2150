/** @brief 8 Puzzle game 
 *  @class Class of the topo graph class
 *  @author Rod Dong
 *  @date 2021/12/3
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include <list>
#include<set>
#include<math.h>
#include<unordered_map>

using namespace std;


/**
 * @param v vector
 * @return int
 */
int getInversions(vector<int> vec){
    int count = 0;
    for(int i = 0; i<vec.size()-1;i++){
        for(int j = i+1; j<vec.size(); j++){
            if(vec[i]>vec[j]&&vec[i]!=0&&vec[j]!=0){
                count++;
            }
        }
    }
    return count;
}


/**
 * @param v 2d vector
 * @return boolean 
 */
bool solvable(vector<vector<int>> vec){
    int count = 0;
    for(int i = 0; i<vec.size(); i++){
        count+=getInversions(vec[i]);
    }
    for(int k = 0; k<vec.size(); k++){
        for(int i = 0; i<vec.size()-1;i++){
            for(int j = i+1; j<vec.size(); j++){
                if(vec[i][k]>vec[j][k]&&vec[i][k]!=0&&vec[j][k]!=0){
                    count++;
                }
                if(k == 0){
                    if(vec[i][k]>vec[j][k+1]&&vec[i][k]!=0&&vec[j][k+1]!=0){
                        count++;
                    }
                    if(vec[i][k]>vec[j][k+2]&&vec[i][k]!=0&&vec[j][k+2]!=0){
                        count++;
                    }
                }
                if(k == 1){
                    if(vec[i][k]>vec[j][k-1]&&vec[i][k]!=0&&vec[j][k-1]!=0){
                        count++;
                    }
                    if(vec[i][k]>vec[j][k+1]&&vec[i][k]!=0&&vec[j][k+1]!=0){
                        count++;
                    }
                }
                if(k == 2){
                    if(vec[i][k]>vec[j][k-1]&&vec[i][k]!=0&&vec[j][k-1]!=0){
                        count++;
                    }
                    if(vec[i][k]>vec[j][k-2]&&vec[i][k]!=0&&vec[j][k-2]!=0){
                        count++;
                    }
                }
            }
        }
    }
    return (count%2 == 0);
}


/**
 * @brief prints the matrix out
 * @param vec 2d vector 
 * @return void
 */
void printMatrix(vector<vector<int>> vec){
    for(int i = 0; i<vec.size();i++){
        for(int j = 0; j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}


void moveLeft(vector<vector<int>>& vec, int x1, int y1){
    if(x1>vec.size()||y1>vec[x1].size()||y1-1<0){
        cout<<"invalid x y coordinate"<<endl;
    }else{
        int temp = vec[x1][y1];
        vec[x1][y1] = vec[x1][y1-1];
        vec[x1][y1-1] = temp;
    }
}


void moveRight(vector<vector<int>>& vec, int x1, int y1){
    if(x1>vec.size()||y1>vec[x1].size()||y1+1>2){
        cout<<"invalid x y coordinate"<<endl;
    }else{
        int temp = vec[x1][y1];
        vec[x1][y1] = vec[x1][y1+1];
        vec[x1][y1+1] = temp;
    }
}


void moveUp(vector<vector<int>>& vec, int x1, int y1){
    if(x1>vec.size()||y1>vec[x1].size()||x1-1<0){
        cout<<"invalid x y coordinate"<<endl;
    }else{
        int temp = vec[x1][y1];
        vec[x1][y1] = vec[x1-1][y1];
        vec[x1-1][y1] = temp;
    }
}


void moveDown(vector<vector<int>>& vec, int x1, int y1){
    if(x1>vec.size()||y1>vec[x1].size()||x1+1>2){
        cout<<"invalid x y coordinate"<<endl;
    }else{
        int temp = vec[x1][y1];
        vec[x1][y1] = vec[x1+1][y1];
        vec[x1+1][y1] = temp;
    }
}


vector<int> getEmptyIndex(vector<vector<int>> vec){
    vector<int> temp(2);
    for(int i = 0; i<vec.size();i++){
        for(int j = 0; j<vec[i].size();j++){
            if(vec[i][j] == 0){
                temp[0] = i;
                temp[1] = j;
                return temp;
            }
        }
    }
    cout<<"no empty space found"<<endl;
    return temp;
}


vector<int> getIndex(vector<vector<int>> vec, int a){
    vector<int> temp(2);
    for(int i = 0; i<vec.size();i++){
        for(int j = 0; j<vec[i].size();j++){
            if(vec[i][j] == a){
                temp[0] = i;
                temp[1] = j;
                return temp;
            }
        }
    }
    cout<<"not found"<<endl;
    return temp;
}


vector<vector<vector<int>>> getChild(vector<vector<int>> vec){
    vector<int> emptySpot = getEmptyIndex(vec);
    int emptyX = emptySpot[0];
    int emptyY = emptySpot[1];
    vector<vector<vector<int>>> children;
    vector<vector<int>> child = vec;
    if(emptyX == 0){
        moveDown(child, emptyX, emptyY);
        children.push_back(child);
        child = vec;
        if(emptyY == 0||emptyY == 1){
            moveRight(child, emptyX, emptyY);
            children.push_back(child);
            child = vec;
        }
        if(emptyY == 1||emptyY == 2){
            moveLeft(child, emptyX, emptyY);
            children.push_back(child);
            child = vec;
        }
    }else if(emptyX == 1){
        moveDown(child, emptyX, emptyY);
        children.push_back(child);
        child = vec;
        moveUp(child, emptyX, emptyY);
        children.push_back(child);
        child = vec;
        if(emptyY == 0||emptyY == 1){
            moveRight(child, emptyX, emptyY);
            children.push_back(child);
            child = vec;
        }
        if(emptyY == 1||emptyY == 2){
            moveLeft(child, emptyX, emptyY);
            children.push_back(child);
            child = vec;
        }
    }else if(emptyX == 2){
        moveUp(child, emptyX, emptyY);
        children.push_back(child);
        child = vec;
        if(emptyY == 0||emptyY == 1){
            moveRight(child, emptyX, emptyY);
            children.push_back(child);
            child = vec;
        }
        if(emptyY == 1||emptyY == 2){
            moveLeft(child, emptyX, emptyY);
            children.push_back(child);
            child = vec;
        }
    }
    return children;
    
}

bool compareVec(vector<vector<int>> vec1, vector<vector<int>> vec2){
    for(int i = 0; i<vec1.size();i++){
        for(int j = 0; j<vec1[i].size();j++){
            if(vec1[i][j] != vec2[i][j]){
                return false;
            }
        }
    }
    return true;    
}

string straighten(vector<vector<int>> vec){
    string s = "";
    char c;
    for(int i = 0; i<vec.size();i++){
        for(int j = 0; j<vec[i].size();j++){
            c = '0'+vec[i][j];
            s.push_back(c);
        }
    }
    return s;
}


int main(int argc, char *argv[]){

    cout<<"Enter puzzle"<<endl;

    vector<vector<int>> goal = {{1,2,3},{4,5,6},{7,8,0}} ;
    vector<vector<int>> initial;

    int index = 1;
    for(int i = 0; i<3; i++){
        vector<int>temp(3);
        initial.push_back(temp);
        for(int j = 0; j<3; j++){
            if(index>=argc){
                break;
            }
            initial[i][j] = int(*argv[index]-48);
            index++;
        }
    }
    printMatrix(initial);
    cout<<endl;

    if(!solvable(initial)){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    set<string> s;
    list<vector<vector<int>>> queue;
    vector<vector<vector<int>>> children;
    vector<vector<int>> arr;
    queue.push_back(initial);
    int step = 0;
    while(true){
        int k = queue.size();
        for(int i = 0; i<k; i++){
            arr = queue.front();
            queue.pop_front();
            if(compareVec(arr, goal)){
                cout<<step<<endl;
                exit(0);
            }
            children = getChild(arr);
            for(int j = 0; j< children.size();j++){
                string str = straighten(children[j]);
                if(s.count(str)== 0){
                    s.insert(str);
                    queue.push_back(children[j]);
                }
            }
        }
        step++;
    }
    cout<<step<<endl;
    return 0;
}