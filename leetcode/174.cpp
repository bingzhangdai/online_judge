#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        dungeon[m-1][n-1] = dungeon[m-1][n-1] < 0 ? -dungeon[m-1][n-1] : 0;
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--) {
                int health = INT_MAX;
                if (i != m - 1 && dungeon[i+1][j] < health)
                    health = dungeon[i+1][j];
                if (j != n - 1 && dungeon[i][j+1] < health)
                    health = dungeon[i][j+1];
                if (i != m - 1 || j != n - 1)
                    dungeon[i][j] = max(health - dungeon[i][j], 0);
            }
        return dungeon[0][0] + 1;
    }
};

int main(void) {
    vector<vector<int>> dungeon{ { -2,1,2 },{ -3,-100,1 },{ -4,100,-30 } };
    cout << Solution().calculateMinimumHP(dungeon) << endl;
    return 0;
}
