#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int cur_i = i, cur_j = j, next_val = matrix[cur_i][cur_j];
                for (int k = 0; k < 4; k++) {
                    int next_i = cur_j;
                    int next_j = n - cur_i - 1;
                    swap(matrix[next_i][next_j], next_val);
                    cur_i = next_i;
                    cur_j = next_j;
                }
            }
        }
    }
};

int main(void) {
    vector<vector<int>> nums = { {1,2,3}, {4,5,6}, {7,8,9} };
    Solution().rotate(nums);
    // system("pause");
    return 0;
}
