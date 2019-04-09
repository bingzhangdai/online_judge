#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1E-3

class Solution {
    bool res = false;
    const double target = 24;
    bool reduce(deque<double>& nums) {
        if (nums.size() == 1 && abs(nums.front() - target) < EPS) {
            return true;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                auto num_i = nums[i], num_j = nums[j];
                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + j);

                nums.push_back(num_i + num_j);
                if (reduce(nums)) return true;
                nums.pop_back();

                nums.push_back(num_i * num_j);
                if (reduce(nums)) return true;
                nums.pop_back();

                nums.push_back(num_i - num_j);
                if (reduce(nums)) return true;
                nums.pop_back();

                nums.push_back(num_j - num_i);
                if (reduce(nums)) return true;
                nums.pop_back();

                if (num_i != 0) {
                    nums.push_back(num_j / num_i);
                    if (reduce(nums)) return true;
                    nums.pop_back();
                }

                if (num_j != 0) {
                    nums.push_back(num_i / num_j);
                    if (reduce(nums)) return true;
                    nums.pop_back();
                }

                nums.insert(nums.begin() + j, num_j);
                nums.insert(nums.begin() + i, num_i);
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        deque<double> nums_new(nums.begin(), nums.end());
        return reduce(nums_new);
    }
};

int main(void) {
    return 0;
}
