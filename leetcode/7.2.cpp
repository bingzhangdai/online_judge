#include <iostream>
#include <string>
#include <climits>
using namespace std;

/*
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321
Example 2:
Input: -123
Output: -321
Example 3:
Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        string res = "";
        if (-(x + 1) == INT_MAX) {
            return 0;
        }
        if (x < 0) {
            x = -x;
            res = res + "-";
        }
        do {
            res += x % 10 + '0';
            x /= 10;
        } while (x);
        auto result = stol(res);
        return result < INT_MIN || result > INT_MAX
                ? 0
                : (int)result;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.reverse(-2147483648) << endl;

    return 0;
}
