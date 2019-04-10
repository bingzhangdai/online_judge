#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example 1: (From the famous "Die Hard" example)
Input: x = 3, y = 5, z = 4
Output: True
Example 2:
Input: x = 2, y = 6, z = 5
Output: False
*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z || z < 0)
            return false;
        if (x < y) swap(x, y);
        if (z == 0)
            return true;
        if (y == 0)
            return x == z;
        for (int i = 0; i < y; i++) {
            if (((long)z + (long)i * x) % y == 0)
                return true;
        }
        return false;
    }
};

int main(void) {
    return 0;
}
