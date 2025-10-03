#include "robot.h"
#include <cstdlib> 
#include "Grid.h"
using namespace std;

void Robot::moveTo(int nx, int ny) {
    x = nx; 
    y = ny; 
}   

// Bresenham's line algorithm
void Robot::lineTo(int nx, int ny, Grid &grid) {
    int x1 = x, y1 = y, x2 = nx, y2 = ny;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        grid.mark(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx)  { err += dx; y1 += sy; }
    }
    x = nx; y = ny;
}

int Robot::getX() const {
    return x; 
}

int Robot::getY() const {
    return y; 
}