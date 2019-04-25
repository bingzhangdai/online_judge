#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> heap;
        if (heightMap.empty() || heightMap.front().empty())
            return 0;
        int m = heightMap.size(), n = heightMap.front().size();
        if (m == 1 || n == 1)
            return 0;
        for (auto i = 0; i < n; i++) {
            heap.emplace(heightMap[0][i], 0, i);
            heightMap[0][i] = INT_MAX;
            heap.emplace(heightMap[m - 1][i], m - 1, i);
            heightMap[m - 1][i] = INT_MAX;
        }
        for (auto i = 1; i < m - 1; i++) {
            heap.emplace(heightMap[i][0], i, 0);
            heightMap[i][0] = INT_MAX;
            heap.emplace(heightMap[i][n - 1], i, n - 1);
            heightMap[i][n - 1] = INT_MAX;
        }
        int max_height = get<0>(heap.top()), res = 0;
        while (!heap.empty()) {
            auto next = heap.top();
            heap.pop();
            auto height = get<0>(next), i = get<1>(next), j = get<2>(next);
            if (height < max_height) {
                res += max_height - height;
            }
            else {
                max_height = height;
            }
            if (i > 0 && heightMap[i - 1][j] != INT_MAX) {
                heap.emplace(heightMap[i - 1][j], i - 1, j);
                heightMap[i - 1][j] = INT_MAX;
            }
            if (j > 0 && heightMap[i][j - 1] != INT_MAX) {
                heap.emplace(heightMap[i][j - 1], i, j - 1);
                heightMap[i][j - 1] = INT_MAX;
            }
            if (i < m - 1 && heightMap[i + 1][j] != INT_MAX) {
                heap.emplace(heightMap[i + 1][j], i + 1, j);
                heightMap[i + 1][j] = INT_MAX;
            }
            if (j < n - 1 && heightMap[i][j + 1] != INT_MAX) {
                heap.emplace(heightMap[i][j + 1], i, j + 1);
                heightMap[i][j + 1] = INT_MAX;
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
