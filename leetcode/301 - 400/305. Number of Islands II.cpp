#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example:
Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:
Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

class Solution {
    unordered_map<int, int> union_set;
    unordered_map<int, int> rank;

    int find(int pos) {
        while (union_set[pos] != pos)
            pos = union_set[pos];
        return pos;
    }

    int join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return 0;
        if (rank[x] < rank[y])
            swap(x, y);
        union_set[y] = x;
        rank[x] += rank[x] == rank[y];
        return 1;
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        int count = 0;
        m += 2, n += 2;
        for (const auto& position : positions) {
            auto x = position[0], y = position[1];
            auto pos(x * n + y);
            count++;
            rank[pos] = 1;
            union_set[pos] = pos;
            for (auto neighbor : { (x - 1) * n + y, (x + 1) * n + y, x * n + y + 1, x * n + y - 1 }) {
                if (rank.find(neighbor) != rank.end()) {
                    count -= join(neighbor, pos);
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
