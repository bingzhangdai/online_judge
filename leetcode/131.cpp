#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
    bool ispalindrome(const string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[--j])
                return false;
        return true;
    }

    void dfs(vector<vector<string>>& res, vector<string>& path, const string& s, int ind) {
        if (ind == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = ind + 1; i <= s.size(); i++) {
            if (ispalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i - ind));
                dfs(res, path, s, i);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(res, path, s, 0);
        return res;
    }
};

int main(void) {
    cout << Solution().partition("aab").size() << endl;
    return 0;
}

/*
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s. 
For example, given s = "aab",
Return 
[
  ["aa","b"],
  ["a","a","b"]
]
*/
