#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty())
            return 0;
        int res = 0, m = grid.size(), n = grid.front().size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                res += 4;
                if (i > 0 && grid[i - 1][j])
                    res--;
                if (i < m - 1 && grid[i + 1][j])
                    res--;
                if (j > 0 && grid[i][j - 1])
                    res--;
                if (j < n - 1 && grid[i][j + 1])
                    res--;
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
