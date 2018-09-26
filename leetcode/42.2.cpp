#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        auto  stk = stack<int>();
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                auto low = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                res += (min(height[stk.top()], height[i]) - low) * (i - stk.top() - 1);
            }
            stk.push(i);
        }
        return res;
    }
};

class Solution1 {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                int tmp = left + 1;
                while (tmp < right && height[tmp] <= height[left]) {
                    res += height[left] - height[tmp];
                    tmp++;
                }
                left = tmp;
            }
            else {
                int tmp = right - 1;
                while (tmp > left && height[tmp] <= height[right]) {
                    res += height[right] - height[tmp];
                    tmp--;
                }
                right = tmp;
            }
        }
        return res;
    }
};

class Solution0 {
public:
    int trap(vector<int>& height) {
        auto dp = vector<int>(height.size());
        int res = 0, h = 0;
        for (int i = 0; i < height.size(); i++) {
            h = max(h, height[i]);
            dp[i] = h;
        }
        h = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            h = max(h, height[i]);
            res += min(h, dp[i]) - height[i];
        }
        return res;
    }
};

int main(void) {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << Solution().trap(height) << endl;
    return 0;
}

