#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (auto c : moves) {
            if (c == 'U')
                y++;
            if (c == 'D')
                y--;
            if (c == 'L')
                x--;
            if (c == 'R')
                x++;
        }
        return x == 0 && y == 0;
    }
};

int main(void) {
    return 0;
}
