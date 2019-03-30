#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n /= 5)
            res += n;
        return res;
    }
};

int main(void) {
    return 0;
}
