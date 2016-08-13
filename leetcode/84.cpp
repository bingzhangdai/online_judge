#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        auto area = 0;
        stack<int> stk;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                auto top = heights[stk.top()];
                stk.pop();
                auto right = stk.empty() ? -1 : stk.top();
                area = max(area, top * (i - right - 1));
            }
            stk.push(i);
        }
        return area;
    }
};

int main(void) {
    vector<int> heights {2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea(heights) << endl;
    // system("pause");
    return 0;
}

