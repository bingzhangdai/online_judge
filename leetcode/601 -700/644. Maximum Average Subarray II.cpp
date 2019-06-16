#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.
*/

class Solution {
    const double EPS = 1e-5;
    const int MAX = 10000;
    const int MIN = -10000;
    bool isAvgGreater(const vector<int>& nums, int k, double mid) {
        double sum = 0, min_sum = 0, prev_sum = 0;
        for (auto i = 0; i < nums.size(); i++) {
            sum += nums[i] - mid;
            if (i >= k)
                min_sum = min(min_sum, prev_sum += nums[i - k] - mid);
            if (i >= k - 1 && sum > min_sum)
                return true;
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = MIN, right = MAX;
        while (right - left > EPS) {
            auto mid = (left + right) / 2;
            if (isAvgGreater(nums, k, mid))
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};

int main(void) {
    return 0;
}
