#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
    // complexity O(s.size() * t.size()), use 'count' instead
    // bool isContains(map<char, int>& res, map<char, int>& str_t) {
    //     for (auto elem : res) {
    //         if (elem.second < str_t[elem.first]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
public:
    string minWindow(string s, string t) {
        map<char, int> str_t;
        map<char, int> res;
        int i = 0, j = 0, len = INT_MAX, ind, count = t.size();
        for (auto c : t) {
            auto pos = str_t.find(c);
            if (pos != str_t.end())
                pos->second++;
            else {
                str_t[c] = 1;
                res[c] = 0;
            }
        }
        while (i < s.size()) {
            auto found = false;
            while (i < s.size() && count) {
                auto pos = res.find(s[i]);
                if (pos != res.end()) {
                    if (str_t[s[i]] > pos->second)
                        count--;
                    pos->second++;
                }
                i++;
            }
            while (count == 0) {
                found = true;
                auto pos = res.find(s[j]);
                if (pos != res.end()) {
                    if (str_t[s[j]] >= pos->second)
                        count++;
                    pos->second--;
                }
                j++;
            }
            if (found && i - j + 1 < len) {
                ind = j - 1;
                len = i - j + 1;
            }
        }
        return (len < INT_MAX) ? s.substr(ind, len) : "";
    }
};

int main(void) {
    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
    // system("pause");
    return 0;
}

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n). 
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC". 
Note:
If there is no such window in S that covers all characters in T, return the empty string "". 
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/
