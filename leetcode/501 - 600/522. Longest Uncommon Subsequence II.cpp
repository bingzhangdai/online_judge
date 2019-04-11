#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Improved
class Solution {
    bool isSubstr(const string& a, const string& b) {
        if (a.length() > b.length())
            return false;
        int i = 0;
        for (auto c : a) {
            while (i < b.length() && b[i] != c)
                i++;
            if (i == b.length())
                return false;
            i++;
        }
        return true;
    }
public:
    int findLUSlength(vector<string> & strs) {
        sort(strs.begin(), strs.end(), [](const string & a, const string & b) {
            return a.length() > b.length();
        });
        for (int i = 0; i < strs.size(); i++) {
            bool uncommon = true;
            for (int j = 0; j < strs.size(); j++) {
                if (j != i && isSubstr(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            if (uncommon)
                return strs[i].length();
        }
        return -1;
    }
};
/*
// Brutal force
class Solution {
    void dfs(const string& s, int ind, string path, vector<string>& substrs) {
        if (ind == s.length()) {
            substrs.push_back(path);
            return;
        }
        while (ind < s.length()) {
            dfs(s, ind + 1, path + s[ind], substrs);
            ind++;
        }
    }
    vector<string> substrs(const string& s) {
        vector<string> res;
        dfs(s, 0, "", res);
        return res;
    }
    bool isSubstr(const string& a, const string& b) {
        int i = 0;
        for (auto c : a) {
            while (i < b.length() && b[i] != c)
                i++;
            if (i == b.length())
                return false;
            i++;
        }
        return true;
    }
public:
    int findLUSlength(vector<string> & strs) {
        string res = "";
        for (int i = 0; i < strs.size(); i++) {
            for (const auto& substr : substrs(strs[i])) {
                bool uncommon = true;
                for (int j = 0; j < strs.size(); j++) {
                    if (j == i)
                        continue;
                    if (isSubstr(substr, strs[j])) {
                        uncommon = false;
                        break;
                    }
                }
                if (uncommon && substr.length() > res.length())
                    res = substr;
            }
        }
        if (res.length() == 0)
            return -1;
        return res.length();
    }
};
*/

int main(void) {
    return 0;
}
