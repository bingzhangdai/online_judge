#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), length = 0, start = 0;
        auto dp = vector<vector<bool>>(n, vector<bool>(n, false));
        for (auto j = 0; j < n; j++) {
            for (auto i = 0; i <= j; i++) {
                if (s[i] == s[j] && (i + 1 >= j - 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (length < j - i + 1) {
                        start = i;
                        length = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start, length);
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.longestPalindrome("a") << endl;

    return 0;
}
