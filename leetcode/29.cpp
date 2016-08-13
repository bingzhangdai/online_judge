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
        if (divisor == 0)
            return INT_MAX;
        int sign = 1;
        long long ndividend(dividend), ndivisor(divisor);
        if (divisor < 0) {
            ndivisor = -ndivisor;
            sign = -sign;
        }
        if (dividend < 0) {
            ndividend = -ndividend;
            sign = -sign;
        }
        long long shift(0), tmp(ndividend);
        while (tmp >= ndivisor) {
            tmp = tmp >> 1;
            shift++;
        }
        unsigned res = 0;
        while (shift--) {
            long long tmp = ndivisor << shift;
            if (ndividend >= tmp) {
                ndividend -= tmp;
                res += 1 << shift;
            }
        }
        if (sign * static_cast<long long>(res) > INT_MAX)
            return INT_MAX;
        if (sign * static_cast<long long>(res) < INT_MIN)
            return INT_MIN;
        return sign * res;
    }
};

int main(void) {
    cout << Solution().divide(INT_MIN, 2) << endl;
    return 0;
}
