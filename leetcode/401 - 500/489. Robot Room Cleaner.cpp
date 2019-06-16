#include <iostream>
#include <vector>
using namespace std;

 // This is the robot's control interface.
 // You should not implement it, or speculate about its implementation
class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};

class Solution {
    enum DIR {
        UP = 0,
        RIGHT = 1,
        DOWN = 2,
        LEFT = 3,
    };
    const vector<DIR> directions = vector<DIR>{UP, DOWN, LEFT, RIGHT};
    void turn(Robot& robot, DIR& state, DIR direction) {
        if (state == direction)
            return;
        if ((state + 1) % 4 == direction)
            robot.turnRight();
        else if ((direction + 1) % 4 == state)
            robot.turnLeft();
        else {
            robot.turnLeft();
            robot.turnLeft();
        }
        state = direction;
    }
    pair<int, int> next_pos(DIR direction, const pair<int, int>& pos) {
        auto next = pos;
         switch (direction) {
             case UP: next.second++; break;
             case DOWN: next.second--; break;
             case LEFT: next.first--; break;
             case RIGHT: next.first++; break;
        }
         return next;
    }
    bool go(Robot& robot, DIR& state, pair<int, int>& pos, DIR direction) {
        turn(robot, state, direction);
        auto res = robot.move();
        if (res)
            pos = next_pos(direction, pos);
        return res;
    }
    DIR oppo_dir(DIR direction) {
        return DIR((direction + 2) % 4);
    }
    string pos_to_string(const pair<int, int>& pos) {
        return to_string(pos.first) + ',' + to_string(pos.second);
    }
    void dfs(Robot& robot, pair<int, int> pos, DIR& state, unordered_set<string>& visited) {
        robot.clean();
        visited.insert(pos_to_string(pos));
        for (auto direction : directions) {
            auto next = next_pos(direction, pos);
            if (visited.find(pos_to_string(next)) == visited.end() && go(robot, state, pos, direction)) {
                dfs(robot, next, state, visited);
                go(robot, state, pos, oppo_dir(direction));
            }
        }
    }
public:
    void cleanRoom(Robot& robot) {
        auto state = UP;
        pair<int, int> pos(0, 0);
        unordered_set<string> visited;
        dfs(robot, pair<int, int>(0,0), state, visited);
    }
};

int main(void) {
    return 0;
}
