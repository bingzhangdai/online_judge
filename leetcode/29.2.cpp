#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        unsigned int udividend = dividend < 0 ? (sign = -sign, -static_cast<unsigned>(dividend)) : dividend;
        unsigned int udivisor = divisor < 0 ? (sign = -sign, -static_cast<unsigned>(divisor)) : divisor;

        int shift = 0;
        unsigned int res = 0;
        for (auto tmp = udividend; tmp >= udivisor; tmp = tmp >> 1, shift++);
        while (shift--) {
            auto tmp = udivisor << shift;
            if (udividend >= tmp) {
                udividend -= tmp;
                res += 1 << shift;
            }
        }
        return sign == 1 ? (res == -static_cast<unsigned>(INT_MIN) ? INT_MAX : res) : res * sign;
    }
};

int main(void) {
    
    cout << Solution().divide(INT_MIN, 2) << endl;
    return 0;
}
