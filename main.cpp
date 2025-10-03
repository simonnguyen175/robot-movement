#include <iostream>
#include <fstream>
#include "Command.h"
#include "Robot.h"
#include "Grid.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Grid grid;
    Robot robot;

    ifstream fin("../input.txt");
    if (!fin) {
        cerr << "Error: could not open input.txt\n";
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        handleCommand(line, robot, grid);
    }

    grid.print();
    return 0;
}
