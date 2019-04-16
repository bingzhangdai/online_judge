#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    int toInt(char c) {
        if (c <= 'z')
            return c - 'a';
        return c - 'A';
    }

public:
    string frequencySort(string s) {
        unordered_map<char, int> hash_map;
        for (auto c : s)
            hash_map[c]++;
        vector<pair<int, char>> freq;
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it)
            freq.emplace_back(it->second, it->first);
        sort(freq.begin(), freq.end(), greater<>());
        string res = "";
        for (auto p : freq) {
            while (p.first--)
                res += p.second;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
