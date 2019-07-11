#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    static const int n = 'z' - 'a' + 1;
public:
    string alienOrder(vector<string>& words) {
        if (words.empty())
            return "";
        if (words.size() == 1)
            return words.front();
        vector<int> inorder(n, 0);
        vector<vector<int>> edges(n, vector<int>());
        vector<bool> seen(n, false);
        // build dependency
        for (auto i = 1; i < words.size(); i++) {
            const auto &s = words[i - 1], t = words[i];
            auto len = min(s.length(), t.length());
            for (auto j = 0; j < len; j++) {
                if (s[j] != t[j]) {
                    inorder[t[j] - 'a']++, edges[s[j] - 'a'].push_back(t[j] - 'a');
                    break;
                }
            }
            for (auto j = 0; j < s.length(); j++)
                seen[s[j] - 'a'] = true;
            for (auto j = 0; j < t.length(); j++)
                seen[t[j] - 'a'] = true;
        }
        string res = "";
        while (true) {
            char t = ' ';
            bool rem = false;
            for (auto i = 0; i < n; i++) {
                if (!seen[i])
                    continue;
                if (inorder[i] > 0)
                    rem = true;
                else if (inorder[i] == 0) {
                    t = i + 'a', res.push_back(t), seen[i] = false;
                    for (auto next : edges[i])
                        inorder[next]--;
                }
            }
            if (rem && t == ' ')
                return "";
            if (!rem)
                break;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
