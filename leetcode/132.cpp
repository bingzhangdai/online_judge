#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// dfs
// OH, TLE
class Solution {
    int min_cut = INT_MAX;
    bool ispalindrome(const string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[--j])
                return false;
        return true;
    }
    void dfs(const string& s, int ind, int num_cut) {
        if (ind == s.size()) {
            min_cut = min(min_cut, num_cut - 1);
            return;
        }
        for (int i = ind + 1; i <= s.size(); i++) {
            if (ispalindrome(s, ind, i))
                dfs(s, i, num_cut + 1);
        }
    }
public:
    int minCut(string s) {
        dfs(s, 0, 0);
        return min_cut;
    }
};
*/

/*
// pseudo-dp
// TLE again, it is no surprise
class Solution {
    bool ispalindrome(const string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[--j])
                return false;
        return true;
    }
    int min_cut(const string& s, int i, int j) {
        if (ispalindrome(s, i, j))
            return 0;
        int num_cut = INT_MAX;
        for (int ind = i + 1; ind < j; ind++)
            num_cut = min(num_cut, 1 + min_cut(s, i, ind) + min_cut(s, ind, j));
        return num_cut;
    }
public:
    int minCut(string s) {
        return min_cut(s, 0, s.size());
    }
};
*/

/*
// dp will also lead to TLE, ╮(╯▽╰)╭
class Solution {
    bool ispalindrome(const string& s, int i, int j, vector<vector<bool>>& dp) {
        dp[i][j] = s[j] == s[j+i];
        if (i - 1 != 0)
            dp[i][j] = dp[i][j] && dp[i-2][j+1];
        return dp[i][j];
    }
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<bool>> dp_palindrome(n, vector<bool>(n, true));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (ispalindrome(s, i, j, dp_palindrome))
                    dp[i][j] = 0;
                else {
                    int min_cut = INT_MAX;
                    for (int k = 0; k < i; k++)
                        min_cut = min(min_cut, 1 + dp[k][j] + dp[i-k-1][j+k+1]);
                    dp[i][j] = min_cut;
                }
            }
        }
        return dp[n-1][0];
    }
};
*/

// previous dp is O(n^3)
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<vector<bool>> dp_palindrome(n, vector<bool>(n, true));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                dp_palindrome[i][j] = s[j] == s[j+i];
                if (i - 1 != 0)
                    dp_palindrome[i][j] = dp_palindrome[i][j] && dp_palindrome[i-2][j+1];
            }
        }
        vector<int> dp_cut(n);
        for (int i = 0; i < n; i++) {
            if (dp_palindrome[i][0])
                dp_cut[i] = 0;
            else {
                int min_cut = dp_cut[i-1] + 1;
                for (int j = 1; j < i; j++) {
                    if (dp_palindrome[i-j][j])
                        min_cut = min(min_cut, 1 + dp_cut[j-1]);
                }
                dp_cut[i] = min_cut;
            }
        }
        return dp_cut.back();
    }
};


int main(void) {
    cout << Solution().minCut("cabababcbc") << endl;
    return 0;
}
/*
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return the minimum cuts needed for a palindrome partitioning of s. 
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/