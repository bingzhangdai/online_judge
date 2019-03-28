#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        auto n = nums.size();
        if (n <= 1)
            return 0;
        int max_n = *max_element(nums.begin(), nums.end()),
            min_n = *min_element(nums.begin(), nums.end());
        double bucket_size = ((double)max_n - (double)min_n) / (n - 1);
        if (bucket_size == 0)
            return 0;
        auto max_bucket = vector<int>(n, INT_MIN);
        auto min_bucket = vector<int>(n, INT_MAX);
        for (auto num : nums) {
            int i = (num - min_n) / bucket_size;
            if (max_bucket[i] < num) {
                max_bucket[i] = num;
            }
            if (min_bucket[i] > num) {
                min_bucket[i] = num;
            }
        }
        int gap = INT_MIN, curr = max_bucket[0];
        for (int i = 1; i < n; i++) {
            if (min_bucket[i] != INT_MAX) {
                if (min_bucket[i] - curr > gap) {
                    gap = min_bucket[i] - curr;
                }
                curr = max_bucket[i];
            }
        }
        return gap;
    }
};

int main(void) {
    vector<int> test {3, 6, 9, 1};
    cout << Solution().maximumGap(test) << endl;
    return 0;
}
