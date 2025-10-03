#include "Command.h"
#include <cstdio>
#include <iostream>

using namespace std;

DimensionCommand::DimensionCommand(int n) : n(n) {}
void DimensionCommand::execute(Robot& robot, Grid& grid) {
    if (n > 0) {
        grid.resize(n);
    } else {
        cerr << "DIMENSION must be > 0\n";
    }
}

MoveToCommand::MoveToCommand(int x, int y) : x(x), y(y) {}
void MoveToCommand::execute(Robot& robot, Grid& grid) {
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid.size()) {
        robot.moveTo(x, y);
    } else {
        cerr << "MOVE_TO out of bounds: (" << x << "," << y << ")\n";
    }
}

LineToCommand::LineToCommand(int x, int y) : x(x), y(y) {}
void LineToCommand::execute(Robot& robot, Grid& grid) {
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid.size()) {
        robot.lineTo(x, y, grid);
    } else {
        cerr << "LINE_TO out of bounds: (" << x << "," << y << ")\n";
    }
}

void handleCommand(const string& line, Robot& robot, Grid& grid) {
    unique_ptr<Command> cmd;

    if (line.rfind("DIMENSION", 0) == 0) {
        int n;
        if (sscanf(line.c_str(), "DIMENSION %d", &n) == 1) {
            cmd = make_unique<DimensionCommand>(n);
        }
    }
    else if (line.rfind("MOVE_TO", 0) == 0) {
        int x, y;
        if (sscanf(line.c_str(), "MOVE_TO %d,%d", &x, &y) == 2) {
            cmd = make_unique<MoveToCommand>(x, y);
        }
    }
    else if (line.rfind("LINE_TO", 0) == 0) {
        int x, y;
        if (sscanf(line.c_str(), "LINE_TO %d,%d", &x, &y) == 2) {
            cmd = make_unique<LineToCommand>(x, y);
        }
    }

    if (cmd) {
        cmd->execute(robot, grid);
    } else {
        cerr << "Wrong command format or unknown command: " << line << "\n";
    }
}
