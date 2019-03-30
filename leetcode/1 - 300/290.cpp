#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    vector<string> split(string str) {
        vector<string> strs;
        int i = 0;
        while (i < str.length()) {
            auto j = str.find(' ', i);
            j = j == -1 ? str.size() : j;
            strs.push_back(str.substr(i, j - i));
            i = j + 1;
        }
        return strs;
    }
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hash_map1;
        unordered_map<string, char> hash_map2;
        auto strs = split(str);
        if (pattern.length() != strs.size())
            return false;
        for (int i = 0; i < pattern.length(); i++) {
            auto s = hash_map1.find(pattern[i]);
            if (s == hash_map1.end())
                hash_map1[pattern[i]] = strs[i];
            else if (s->second != strs[i])
                return false;
            auto s2 = hash_map2.find(strs[i]);
            if (s2 == hash_map2.end())
                hash_map2[strs[i]] = pattern[i];
            else if (s2->second != pattern[i])
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
