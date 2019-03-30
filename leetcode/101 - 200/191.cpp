#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t b = 0x1;
        int res = 0;
        do {
            if (b & n)
                res++;
        } while (b <<= 1);
        return res;
    }
};

int main(void) {
    cout << Solution().hammingWeight(0b00000000000000000000000000001011) << endl;
    return 0;
}
