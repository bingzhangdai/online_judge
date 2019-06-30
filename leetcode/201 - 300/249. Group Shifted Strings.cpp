#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    inline void next(string& str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'z')
                str[i] = 'a';
            else
                str[i]++;
        }
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_multiset<string> hash_set(strings.begin(), strings.end());
        vector<vector<string>> res;
        while (!hash_set.empty()) {
            vector<string> group;
            auto str = *hash_set.begin();
            for (int i = 0; i < 26; i++) {
                auto it = hash_set.end();
                while ((it = hash_set.find(str)) != hash_set.end()) {
                    hash_set.erase(it);
                    group.push_back(str);
                }
                next(str);
            }
            res.push_back(group);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
