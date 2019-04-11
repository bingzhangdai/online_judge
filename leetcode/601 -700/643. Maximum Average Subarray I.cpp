#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double max_sum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            if ((sum -= nums[i - k]) > max_sum)
                max_sum = sum;
        }
        return k == 0 ? 0 : max_sum / k;
    }
};

int main(void) {
    return 0;
}
