#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (const auto& w : words) {
            if (w.length() != pattern.length())
                continue;
            vector<char> p('z' - 'a' + 1, '*');
            vector<bool> visited('z' - 'a' + 1, false);
            auto is_match = true;
            for (auto i = 0; i < w.length(); i++) {
                if (p[w[i] - 'a'] != '*') {
                    if (p[w[i] - 'a'] != pattern[i]) { 
                        is_match = false;
                        break;
                    }
                    else
                        continue;
                }
                if (visited[pattern[i] - 'a']) {
                    is_match = false;
                    break;
                }
                visited[pattern[i] - 'a'] = true;
                p[w[i] - 'a'] = pattern[i];
            }
            if (is_match)
                res.push_back(w);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
