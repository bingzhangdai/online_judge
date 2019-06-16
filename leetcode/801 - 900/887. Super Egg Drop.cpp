#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int> dp(K + 1, 0), tmp(K + 1, 0);
        auto res = 0;
        while (dp.back() < N) {
            res++;
            for (auto i = 1; i <= K; i++) {
                tmp[i] = dp[i - 1] + 1 + dp[i];
            }
            swap(dp, tmp);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
