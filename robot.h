#pragma once

#include "grid.h"

class Robot {
    int x, y; 
public:
    Robot(): x(0), y(0) {};
    Robot(int x, int y): x(x), y(y) {};
    void moveTo(int nx, int ny);
    void lineTo(int nx, int ny, Grid &grid); 
    int getX() const; 
    int getY() const; 
}; 