#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    bool isMatch(char s, char p) {
        return p == '.' || p == s;
    }
    bool isMatchDfs(const string& s, int i, const string& p, int j) {
        if (j + 1 < p.length() && p[j + 1] == '*' && isMatchDfs(s, i, p, j + 2))
            return true;
        if (i == s.length() || j == p.length())
            return i == s.length() && j == p.length();
        if (j + 1 < p.length() && p[j + 1] == '*') {
            for (int k = 0; k + i < s.length() && isMatch(s[i + k], p[j]); k++) {
                if (isMatchDfs(s, i + k + 1, p, j + 2))
                    return true;
            }
            return false;
        }
        else {
            return isMatch(s[i], p[j]) && isMatchDfs(s, i + 1, p, j + 1);
        }
    }
public:
    bool isMatch(string s, string p) {
        return isMatchDfs(s, 0, p, 0);
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.isMatch("ab", ".*c") << endl;
    return 0;
}

/*
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/