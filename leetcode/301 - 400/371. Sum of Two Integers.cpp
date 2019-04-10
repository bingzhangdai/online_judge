#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int bit = 1, carry = 0, res = 0;
        if (a & bit && b & bit && carry) {
            carry = 1;
            res += bit;
        }
    }
};

int main(void) {
    return 0;
}
