#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), max_len = 0;
        auto dp = new int[len];
        for (int i = 0; i < len; i++)
            dp[i] = 0;
        for (int j = 1; j < len; j++) {
            // ()(
            if (s[j] == '(')
                continue;
            // )()()
            if (s[j - 1] == '(') {
                if (j - 2 < 0)
                    dp[j] = max(dp[j], 2);
                else
                    dp[j] = max(dp[j], dp[j - 2] + 2);
            }
            // ()(())
            int i = j - 1 - dp[j - 1];
            if (i >= 0 && s[i] == '(') {
                if (i - 1 >= 0)
                    dp[j] = max(dp[j], dp[j - 1] + 2 + dp[i - 1]);
                else
                    dp[j] = max(dp[j], dp[j - 1] + 2);
            }
            max_len = max(max_len, dp[j]);
        }

        delete[] dp;
        return max_len;
    }
    //int longestValidParentheses(string s) {
    //    int len = s.length();
    //    int **dp = new int *[len];
    //    for (int i = 0; i < len; i++)
    //        dp[i] = new int[len];

    //    int len_max = 0;
    //    for (int j = 0; j < len; j++) {
    //        dp[j][j] = INT_MIN;
    //        if (s[j] == '(') {
    //            for (int i = 0; i < j; i++)
    //                dp[i][j] = INT_MIN;
    //            continue;
    //        }
    //        for (int i = 0; i < j; i++) {
    //            if (i == j - 1 && s[i] == '(') {
    //                dp[i][j] = 2;
    //                len_max = max(len_max, dp[i][j]);
    //                continue;
    //            }
    //            dp[i][j] = INT_MIN;
    //            if (s[j - 1] == '(')
    //                dp[i][j] = max(dp[i][j], dp[i][j - 2] + 2);
    //            if (s[i] == '(')
    //                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
    //            len_max = max(len_max, dp[i][j]);
    //        }
    //    }

    //    for (int i = 0; i < len; i++)
    //        delete[] dp[i];
    //    delete[] dp;
    //    return len_max;
    //}
};

int main(void) {
    cout << Solution().longestValidParentheses("(()") << endl;
    // system("pause");
    return 0;
}
