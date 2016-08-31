#include <iostream>
#include <vector>
#include <deque>
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
    bool ispalindrome(const string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[--j])
                return false;
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (ispalindrome(s, j, i + 1 + j))
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

class Solution {
public:
    int minCut(string s) {
        
    }
};

int main(void) {
    cout << Solution().minCut("aabbc") << endl;
    return 0;
}
/*
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return the minimum cuts needed for a palindrome partitioning of s. 
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/