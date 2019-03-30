#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), max_len = 0;
        auto dp = vector<int>(n, 0);
        for (auto i = 1; i < n; i++) {
            if (s[i] == '(')
                continue;
            auto ind = s[i - 1] == '(' ? i - 1 : i - 1 - dp[i - 1];
            auto len = ind >= 0 ? (s[ind] == '(' ? 2 + dp[i - 1] : 0) : 0;
            len += len && ind - 1 >= 0 ? dp[ind - 1] : 0;
            dp[i] = len;
            max_len = max(len, max_len);
        }
        return max_len;
    }
};

int main(void) {
    cout << Solution().longestValidParentheses("((())(())") << endl;

    return 0;
}
