#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int, int> hash_map;
        int hash_val = 0;
        for (int i = 0; i < s.size(); i++) {
            hash_val = (hash_val << 3) & 0x3fffffff | s[i] & 0x7;
            auto cnt = ++hash_map[hash_val];
            if (cnt == 2)
                res.push_back(s.substr(i - 9, 10));
        }
        return res;
    }
};

int main(void) {
    return 0;
}
