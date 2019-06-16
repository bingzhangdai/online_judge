#include <iostream>
using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (true) {
            if (tx == sx && ty == sy)
                return true;
            if (tx < sx || ty < sy || tx == ty)
                return false;
            if (tx > ty)
                tx -= max((tx - sx) / ty, 1) * ty;
            else
                ty -= max((ty - sy) / tx, 1) * tx;
        }
    }
};

int main(void) {
    return 0;
}
