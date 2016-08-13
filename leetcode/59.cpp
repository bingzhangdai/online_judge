#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        auto res = vector<vector<int>>(n, vector<int>(n, 0));
        int num = 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i; j < n - i; j++)
                res[i][j] = num++;
            for (int j = i + 1; j < n - i; j++)
                res[j][n - i - 1] = num++;
            for (int j = n - i - 2; j > i; j--)
                res[n - i - 1][j] = num++;
            for (int j = n - i - 1; j > i; j--)
                res[j][i] = num++;
        }
        return res;
    }
};

int main(void) {
    cout << Solution().generateMatrix(3).size() << endl;
    // system("pause");
    return 0;
}
