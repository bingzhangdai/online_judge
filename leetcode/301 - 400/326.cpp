#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    long max_num = 1;
public:
    Solution() {
        while ((max_num *= 3) < INT_MAX);
    }
    bool isPowerOfThree(int n) {
        return n > 0 && !(max_num % n);
    }
};

int main(void) {
    return 0;
}
