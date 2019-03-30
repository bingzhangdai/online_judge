#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        uint32_t m = 0x1;
        do {
            if (m == n)
                return true;
        } while (m <<= 1);
        return false;
    }
};

int main(void) {
    return 0;
}
