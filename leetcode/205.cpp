#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash_map;
        unordered_set<char> values;
        if (s.length() != t.length())
            return false;
        for (int i = 0; i <s.length(); i++) {
            auto pos = hash_map.find(s[i]);
            if (pos == hash_map.end()) {
                if (values.find(t[i]) != values.end())
                    return false;
                hash_map[s[i]] = t[i];
                values.insert(t[i]);
            }
            else if ((*pos).second != t[i])
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
