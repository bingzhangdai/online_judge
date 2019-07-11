#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto c : coins) {
            for (auto i = 0; i + c <= amount; i++) {
                dp[i + c] += dp[i];
            }
        }
        return dp.back();
    }
};

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount + 1, 0);
//         dp[0] = 1;
//         for (auto i = 1; i <= amount; i++) {
//             int count = 0;
//             for (auto c : coins)
//                 count += (i - c >= 0) ? dp[i - c] : 0;
//             dp[i] = count;
//         }
//         return dp.back();
//     }
// };

int main(void) {
    return 0;
}
