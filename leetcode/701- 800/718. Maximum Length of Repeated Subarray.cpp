#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty())
            return 0;
        int m = A.size(), n = B.size();
        vector<int> dp(m + 1, 0);
        for (auto b : B) {
            for (int i = m; i > 0; i--) {
                dp[i] = A[i - 1] == b ? (dp[i - 1] + 1) : 0;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(void) {
    return 0;
}
