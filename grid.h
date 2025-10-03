#pragma once

#include <vector>
#include <iostream> 

using namespace std; 

class Grid {
    int n; 
    vector<vector<char>> cells; 

public:
    Grid() : n(0) {}
    Grid(int nsize);
    void resize(int nsize); 
    void mark(int x, int y); 
    void print() const; 
    int size() const;     
}; 