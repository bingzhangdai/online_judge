#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int backtracking_p = -1, backtracking_s = -1, i, j;
        for (i = j = 0; i < s.length();) {
            if (s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
            }
            else if (p[j] == '*') {
                backtracking_p = j + 1;
                backtracking_s = i;
                j = backtracking_p;
            }
            else if (backtracking_p != -1) {
                j = backtracking_p;
                i = ++backtracking_s;
            }
            else
                return false;
        }
        while (j < p.length() && p[j] == '*')
            j++;
        if (i == s.length() && j == p.length())
            return true;
        return false;
    }
};

// TLE T_T
// class Solution {
//     bool dfs(string& s, string& p, int s_i, int p_i) {
//         if (s_i == s.length() && p_i == p.length())
//             return true;
//         else if (s_i == s.length() && p_i != p.length()) {
//             if (p[p_i] == '*')
//                 return dfs(s, p, s_i, p_i + 1);
//             return false;
//         }
//         else if (s_i != s.length() && p_i == p.length())
//             return false;
//         // take care multiple *s
//         // e.g. *****b*aba***
//         if (p[p_i] == '*') {
//             while (++p_i < p.length() && p[p_i] == '*');
//             while (s_i <= s.length()) {
//                 if (dfs(s, p, s_i, p_i))
//                     return true;
//                 s_i++;
//             }
//             return false;
//         }
//         else if (p[p_i] == '?') {
//             return dfs(s, p, s_i + 1, p_i + 1);
//         }
//         // take care
//         else {
//             if (s[s_i] != p[p_i])
//                 return false;
//             return dfs(s, p, s_i + 1, p_i + 1);
//         }
//     }
// public:
//     bool isMatch(string s, string p) {
//         return dfs(s, p, 0, 0);
//     }
// };

int main(void) {
    string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    cout << Solution().isMatch(s, p) << endl;
    // system("pause");
    return 0;
}
