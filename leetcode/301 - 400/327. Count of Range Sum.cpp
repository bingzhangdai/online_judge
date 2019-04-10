#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3 
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        deque<long> sums{ 0 };
        long sum = 0, res = 0;
        for (auto num : nums) {
            sum += num;
            auto lower_bound = std::lower_bound(sums.begin(), sums.end(), sum - upper);
            auto upper_bound = std::upper_bound(sums.begin(), sums.end(), sum - lower);
            res += upper_bound - lower_bound;
            lower_bound
            sums.insert(lower_bound, sum);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
