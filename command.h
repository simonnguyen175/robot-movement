#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include <string>
#include "Robot.h"
#include "Grid.h"

class Command {
public:
    virtual void execute(Robot& robot, Grid& grid) = 0;
    virtual ~Command() {}
};

class DimensionCommand : public Command {
    int n;
public:
    DimensionCommand(int n);
    void execute(Robot& robot, Grid& grid) override;
};

class MoveToCommand : public Command {
    int x, y;
public:
    MoveToCommand(int x, int y);
    void execute(Robot& robot, Grid& grid) override;
};

class LineToCommand : public Command {
    int x, y;
public:
    LineToCommand(int x, int y);
    void execute(Robot& robot, Grid& grid) override;
};

void handleCommand(const std::string& line, Robot& robot, Grid& grid);

#endif
