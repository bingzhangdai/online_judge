#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
private:
    bool matched = false;
public:
    bool isMatch(string s, string p) {
        dfs(0, 0, s, p);
        return matched;
    }
    void dfs(int s_n, int p_n, const string& s, const string& p) {
        if (s_n == s.length() && p_n == p.length()) {
            matched = true;
            return;
        }
        else if (s_n == s.length() && p_n != p.length()) {
            while (p_n + 1 < p.length())
                if (p[p_n + 1] == '*')
                    p_n += 2;
                else
                    break;
            if (s_n == s.length() && p_n == p.length())
                dfs(s_n, p_n, s, p); // accept
            return;
        }
        else if (p_n == p.length() && s_n != s.length()) {
            return;
        }
        if (matched)
            return;
        if (p[p_n] == '.') {
            if (p_n + 1 < p.length() && p[p_n + 1] == '*') {
                dfs(s_n, p_n + 2, s, p);
                for (int i = s_n; i < s.length(); i++)
                    dfs(i + 1, p_n + 2, s, p);
                //for (int i = s_n - 1; i < s.length(); i++)
                //    dfs(i + 1, p_n + 2, s, p);
            }
            else
                dfs(s_n + 1, p_n + 1, s, p);
        }
        else {
            if (p_n + 1 < p.length() && p[p_n + 1] == '*') {
                dfs(s_n, p_n + 2, s, p);
                for (int i = s_n; i < s.length() && s[i] == p[p_n]; i++)
                    dfs(i + 1, p_n + 2, s, p);
            }
            else if (s[s_n] == p[p_n])
                dfs(s_n + 1, p_n + 1, s, p);
            else
                return;
        }
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.isMatch("ab", ".*c") << endl;

    system("pause");
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