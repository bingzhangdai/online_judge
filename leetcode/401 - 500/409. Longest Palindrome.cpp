#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash_map;
        for (auto c : s)
            hash_map[c]++;
        bool single = false;
        int res = 0;
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
            if (it->second & 1 && !single) {
                res += it->second;
                single = true;
                continue;
            }
            res += it->second & ~1;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
