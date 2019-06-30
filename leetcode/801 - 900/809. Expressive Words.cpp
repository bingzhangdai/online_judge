#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    vector<pair<char, int>> split(const string& s) {
        vector<pair<char, int>> res;
        for (int i = 0; i < s.length();) {
            int j = i + 1;
            while (j < s.length() && s[j] == s[i])
                j++;
            res.emplace_back(s[i], j - i);
            i = j;
        }
        return res;
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char, int>> target = split(S);
        auto res = 0;
        for (const auto& w : words) {
            auto t = split(w);
            if (t.size() != target.size())
                continue;
            bool strechy = true;
            for (int i = 0; i < target.size(); i++) {
                if (target[i].first != t[i].first) {
                    strechy = false;
                    break;
                }
                if (target[i].second != t[i].second) {
                    if (target[i].second < t[i].second || target[i].second < 3) {
                        strechy = false;
                        break;
                    }
                }
            }
            res += strechy;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
