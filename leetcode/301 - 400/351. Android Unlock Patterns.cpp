#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    const vector<vector<int>> moves0 {
        {1, 5, 4, 7, 3},
        {2, 5, 8, 4, 6, 3, 0},
        {5, 7, 4, 3, 1},
        {0, 1, 2, 4, 8, 7, 6},
        {0, 1, 2, 3, 5, 6, 7, 8},
        {8, 7, 6, 4, 0, 1, 2},
        {3, 1, 4, 5, 7},
        {6, 3, 0, 4, 2, 5, 8},
        {7, 3, 4, 1, 5}
    };
    const vector<unordered_map<int, int>> moves1 {
        {{2, 1}, {8, 4}, {6, 3}},
        {{7, 4}},
        {{0, 1}, {6, 4}, {8, 5}},
        {{5, 4}},
        {},
        {{3, 4}},
        {{0, 3}, {2, 4}, {8, 7}},
        {{1, 4}},
        {{2, 5}, {0, 4}, {6, 7}}
    };
    const unordered_map<int, int> start {{0, 4}, {1, 4}, {4, 1}};
    int dfs(int curr, vector<int>& visited, int m, int n) {
        int res = 0;
        if (m <= 0 && n >= 0)
            res += 1;
        if (n <= 0)
            return res;
        for (auto next : moves0[curr]) {
            if (visited[next])
                continue;
            visited[next] = true;
            res += dfs(next, visited, m - 1, n - 1);
            visited[next] = false;
        }
        for (const auto& next : moves1[curr]) {
            if (visited[next.first] || !visited[next.second])
                continue;
            visited[next.first] = true;
            res += dfs(next.first, visited, m - 1, n - 1);
            visited[next.first] = false;
        }
        return res;
    }
public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<int> visited(9, false);
        for (const auto s : start) {
            visited[s.first] = true;
            res += dfs(s.first, visited, m - 1, n - 1) * s.second;
            visited[s.first] = false;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
