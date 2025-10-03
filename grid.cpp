#include "grid.h"

using namespace std;

Grid::Grid(int size) {
    resize(size); 
}

int Grid::size() const {
    return n; 
}

void Grid::resize(int nsize) {
    n = nsize; 
    cells.assign(n, vector<char>(n, '.')); 
}

void Grid::mark(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n){
        cells[y][x] = '+'; 
    }
    else {
        cerr << "Warning: mark(" << x << "," << y << ") is out of bounds\n"; 
    }
}

void Grid::print() const {
    for (const auto &row : cells) {
        for (const char &cell : row) {
            cout << cell; 
        }
        cout << '\n'; 
    }
}