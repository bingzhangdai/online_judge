#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
    vector<int> placed;
    int res;
    bool isvalid(int ind) {
        for (int i = 0; i < ind; i++) {
            if (placed[i] == placed[ind] || abs(placed[ind] - placed[i]) == abs(ind - i))
                return false;
        }
        return true;
    }
    void dfs(int i) {
        if (i == placed.size()) {
            res++;
            return;
        }
        for (int j = 0; j < placed.size(); j++) {
            placed[i] = j;
            if (isvalid(i))
                dfs(i + 1);
        }
    }
public:
    int totalNQueens(int n) {
        placed = vector<int>(n, -1);
        dfs(0);
        return res;
    }
};

int main(void) {
    cout << Solution().totalNQueens(8) << endl;
    // system("pause");
    return 0;
}
