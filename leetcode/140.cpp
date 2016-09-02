#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

/*
// I know it will result in TLE
class Solution {
    void dfs(const string& s, const unordered_set<string>& wordDict, string path, vector<string>& res, int ind) {
        if (ind == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            if (wordDict.find(s.substr(ind, i - ind + 1)) != wordDict.end())
                if (i == s.size() - 1)
                    dfs(s, wordDict, path + s.substr(ind, i - ind + 1), res, i + 1);
                else
                    dfs(s, wordDict, path + s.substr(ind, i - ind + 1) + " ", res, i + 1);
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        dfs(s, wordDict, "", res, 0);
        return res;
    }
};
*/

// use dp + dfs
class Solution {
    void dfs(const string& s, const vector<vector<int>>& dp, string path, vector<string>& res, int ind) {
        for (auto i : dp[ind]) {
            if (i == 0)
                res.push_back(s.substr(i, ind - i + 1) + path);
            else
                dfs(s, dp, " " + s.substr(i, ind - i + 1) + path, res, i - 1);
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<string> res;
        if (n == 0)
            return res;
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = i; j; j--)
                if (dp[j-1].size() && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end())
                    dp[i].push_back(j);
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end())
                dp[i].push_back(0);
        }
        dfs(s, dp, "", res, n - 1);
        return res;
    }
};

int main(void) {
    unordered_set<string> wordDict {"cat","cats","and","sand","dog"};
    Solution().wordBreak("catsanddog", wordDict);
    return 0;
}
