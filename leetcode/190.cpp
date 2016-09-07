#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t left = 0x10000, right = 0x8000;
        while (right) {
            auto left_half = left & n, right_half = right & n;
            if (left_half && !right_half) {
                n ^= left;
                n |= right;
            }
            else if (!left_half && right_half) {
                n |= left;
                n ^= right;
            }
            left <<= 1;
            right >>= 1;
        }
        return n;
    }
};

int main(void) {
    cout << Solution().reverseBits(43261596) << endl;
    return 0;
}
