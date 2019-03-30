#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class NumArray {
    vector<int> left_sum = vector<int>(1, 0);
    vector<int> right_sum = vector<int>(1, 0);
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return;
        left_sum.resize(n);
        right_sum.resize(n);
        left_sum[0] = nums[0];
        right_sum[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            left_sum[i] = left_sum[i - 1] + nums[i];
        for (int i = n - 2; i >= 0; i--)
            right_sum[i] = right_sum[i + 1] + nums[i];
    }

    int sumRange(int i, int j) {
        return left_sum[j] + right_sum[i] - right_sum[0];
    }
};

int main(void) {
    return 0;
}
