#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
    int largRectArea(vector<int>& heights) {
        auto area = 0;
        stack<int> stk;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                auto top = heights[stk.top()];
                stk.pop();
                int right = stk.empty() ? -1 : stk.top();
                area = max(area, top * (i - right - 1));
            }
            stk.push(i);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size())
            return 0;
        int area = 0, m = matrix.size(), n = matrix[0].size();
        auto heights = vector<vector<int>>(m, vector<int>(n, 0));
        for (auto j = 0; j < n; j++)
            heights[0][j] = (matrix[0][j] == '0') ? 0 : 1;
        for (auto i = 1; i < m; i++)
            for (auto j = 0; j < n; j++)
                heights[i][j] = (matrix[i][j] == '0') ? 0 : (1 + heights[i-1][j]);
        for (auto i = 0; i < m; i++)
            area = max(area, largRectArea(heights[i]));
        return area;
    }
};

int main(void) {
    vector<vector<char>> matrix {{'1','0','1','0','0'},
                                 {'1','0','1','1','1'},
                                 {'1','1','1','1','1'},
                                 {'1','0','0','1','0'}};
    cout << Solution().maximalRectangle(matrix) << endl;
    // system("pause");
    return 0;
}

