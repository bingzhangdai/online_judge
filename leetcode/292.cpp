#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: 4
Output: false 
Explanation: If there are 4 stones in the heap, then you will never win the game;
             No matter 1, 2, or 3 stones you remove, the last stone will always be 
             removed by your friend.
*/

// LTE
/*
class Solution {
public:
    bool canWinNim(int n) {
        vector<bool> dp(n, true);
        for (int j = 3; j < n; j++) {
            dp[j] = !(dp[j-1] && dp[j-2] && dp[j-3]);
        }
        return dp[n-1];
    }
};
*/

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main(void) {
    return 0;
}
