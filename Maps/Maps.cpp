#include <vector>
#include "Maps.h"
#include <time.h>
#include <stdlib.h>
#include <string>
#include <ostream>
#include <iostream>

using namespace std;

int difficulty;
bool initialized = false;
vector<vector<int>> map;

Maps::Maps() {
    initialized = false;
}

Maps::Maps(int x) {
    difficulty = x;
    initialize_map();
    set_points();
    initialized = true;
}

vector<vector<int> > Maps::get_map() {
    return map;
}

void Maps::set_difficulty(int x) {
    difficulty = x;
    if (!initialized) {
        initialize_map();
        set_points();
    }
}

/**
* @method:
*   Init the map vector
*/
void Maps::initialize_map() {
    map(difficulty, vector<int>(difficulty, 0));
    set_points();
}

/**
* @method:
*   This sets the start and end points of our map
*/
void Maps::set_points() {
    srand(time(NULL));
    int start = rand()%difficulty;
    int end = rand()%difficulty;
    // ensure our start/ends aren't the same
    while(start == end) {
        end = rand()%difficulty;
    }
    // set the values so our algorithm knows where
    // to start and end
    map.at(start).at(start) = 1;
    map.at(end).at(end) = 2;
}

void Maps::print_map() {
    string out = "";
    vector< vector<int> >::iterator row;
    vector<int>::iterator column;
    for(row = map.begin(); row != map.end(); row++) {
        for(column = row->begin(); column != row->end(); column++) {
            out += to_string(*column) + " ";
        }
        out += "\n";
    }
    //printf("%s", out);
    cout << out << endl;
}

