#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// wrong greedy
/*
class Solution {
    vector<vector<int>> count = vector<vector<int>>('z' - 'a' + 1, vector<int>());
    const char X = 'z' + 1;
    char letterBehind(const string& s, int i) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[j] != X)
                return s[j];
        }
        return X;
    }
public:
    string removeDuplicateLetters(string s) {
        for (int i = 0; i < s.length(); i++)
            count[s[i] - 'a'].push_back(i);
        int len = 0;
        for (int i = 'z' - 'a'; i >= 0; i--) {
            if (count[i].size())
                len++;
            bool removed = false;
            for (int pos = 0; pos < count[i].size(); pos++) {
                if (removed)
                    s[count[i][pos]] = X;
                else {
                    if (letterBehind(s, count[i][pos]) > s[count[i][pos]] || pos == count[i].size() - 1)
                        removed = true;
                    else
                        s[count[i][pos]] = X;
                }
            }
        }
        string res(len, 'a');
        int i = 0;
        for (auto c : s)
            if (c != X)
                res[i++] = c;
        return res;
    }
};
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count = vector<int>('z' - 'a' + 1, 0);
        int len = 0;
        for (auto c : s) {
            if (!(count[c - 'a']++))
                len++;
        }
        auto res = string(len, '*');
        int pos = 0;
        for (int i = 0; i < len; i++) {
            int curr = pos;
            while (curr < s.length()) {
                if (s[curr] < s[pos] && count[s[curr] - 'a'] > 0|| count[s[pos] - 'a'] <= 0)
                    pos = curr;
                if (--count[s[curr] - 'a'] == 0)
                    break;
                curr++;
            }
            for (int j = curr; j > pos; j--)
                count[s[j] - 'a']++;
            count[s[pos] - 'a'] = 0;
            res[i] = s[pos++];
        }
        return res;
    }
};

int main(void) {
    return 0;
}