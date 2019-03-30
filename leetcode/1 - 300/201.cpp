#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        uint32_t bits = 0xffffffff;
        while ((m &= bits) != (n &= bits))
            bits <<= 1;
        return m;
    }
};

int main(void) {
    return 0;
}
