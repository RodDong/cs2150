#include <iostream>
#include "timer.h"

using namespace std;

extern "C" int threexplusone (int);

int main(){
    int num, itr, steps;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Enter iterations of subroutine: ";
    cin>>itr;
    steps = threexplusone(num);
    timer time;
    time.start();
    for (int i = 0; i < itr; i++){
        threexplusone(num);
    }
    time.stop();
    cout<<"Steps: "<<steps<<endl;
    //cout<<"Runtime is: "<<time<<endl;
}