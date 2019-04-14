#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> res(nums.size(), -1);
        stack<pair<int, int>> stk;
        int n = nums.size();
        for (int i = 0; i < n * 2; i++) {
            auto num = nums[i % n];
            while (!stk.empty() && stk.top().first < num) {
                auto& top = stk.top();
                stk.pop();
                res[top.second] = num;
            }
            stk.emplace(num, i % n);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
