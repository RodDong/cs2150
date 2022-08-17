/** @brief salesman prob
 *  @author Rod Dong
 *  @date 2021/11/30
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    float distance = computeDistance(me, dests[0], dests);
    vector<string> result = dests;
    sort(dests.begin()+1,dests.end());
    while(next_permutation(dests.begin()+1, dests.end())){
        if(computeDistance(me, dests[0], dests)<distance){
            distance = computeDistance(me, dests[0], dests);
            result = dests;
        }
    }
    cout << "Minimum path has distance " << distance << ": ";
    printRoute(result[0], result);
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
    string strt = start;
    float distance = 0;
    for(int i = 0; i<dests.size(); i++){
        distance+=me.getDistance(strt, dests[i]);
        strt = dests[i];
    }
    distance+=me.getDistance(dests[0],dests.back());
    return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    for(int i = 0; i<dests.size(); i++){
        cout<<dests[i]<<" -> "; 
    }
    cout<<start<<endl;
}