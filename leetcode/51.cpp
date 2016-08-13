#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
    vector<int> placed;
    vector<vector<string>> res;
    // bool isvalid(int ind) {
    //     for (int i = 0; i <= ind; i++) {
    //         int j = placed[i];
    //         // column
    //         for (int k = i + 1; k <= ind; k++)
    //             if (placed[k] == j)
    //                 return false;
    //         // diagonal
    //         for (int k = 0; k < ind; k++)
    //             if (k != i && (placed[k] == j + k - i || placed[k] == j - k + i))
    //                 return false;
    //     }
    //     return true;
    // }
    bool isvalid(int ind) {
        for (int i = 0; i < ind; i++) {
            if (placed[i] == placed[ind] || abs(placed[ind] - placed[i]) == abs(ind - i))
                return false;
        }
        return true;
    }
    void push_res() {
        vector<string> solu;
        for (int i = 0; i < placed.size(); i++) {
            string s = "";
            for (int j = 0; j < placed.size(); j++)
                if (j != placed[i])
                    s.push_back('.');
                else
                    s.push_back('Q');
            solu.push_back(s);
        }
        res.push_back(solu);
    }
    void dfs(int i) {
        if (i == placed.size()) {
            push_res();
            return;
        }
        for (int j = 0; j < placed.size(); j++) {
            placed[i] = j;
            if (isvalid(i))
                dfs(i + 1);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        placed = vector<int>(n, -1);
        dfs(0);
        return res;
    }
};

int main(void) {
    cout << Solution().solveNQueens(8).size() << endl;
    // system("pause");
    return 0;
}
