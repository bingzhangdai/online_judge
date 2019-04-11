#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string & l, const string & r) {
            return l.length() > r.length() || l.length() == r.length() && l < r;
        });
        for (const auto& str : d) {
            int i = 0;
            bool found = true;
            for (auto c : str) {
                while (i < s.length() && s[i] != c) {
                    i++;
                }
                if (i == s.length()) {
                    found = false;
                    break;
                }
                i++;
            }
            if (found)
                return str;
        }
        return "";
    }
};

int main(void) {
    return 0;
}
