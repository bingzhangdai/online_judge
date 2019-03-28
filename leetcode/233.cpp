#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
Example:
Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        long bit_in_ten = 1;
        int num_zero = 0, num_one_before = 0, res = 0, num_one = 0;
        while ((num_zero++, bit_in_ten *= 10) < n);
        while ((bit_in_ten /= 10) < n) {
            num_zero--;
            int num_at_this_pos = n / bit_in_ten;
            if (num_at_this_pos == 0)
                continue;
            if (num_at_this_pos == 1)
                num_one++;
            if (num_at_this_pos >= 1)
                res += num_one_before * bit_in_ten * (num_at_this_pos > 2 ? num_at_this_pos - 1 : 1)
                            + countDigitOne(bit_in_ten - 1);
            num_one_before++;
            if (num_at_this_pos > 1)
                res += num_one_before * bit_in_ten + countDigitOne(bit_in_ten - 1);
            n -= bit_in_ten * num_at_this_pos;
        }
        return res + num_one;
    }
};

int main(void) {
    cout << Solution().countDigitOne(100) << endl;
    return 0;
}
