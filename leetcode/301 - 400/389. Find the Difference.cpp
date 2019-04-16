#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash_map;
        for (auto c : t)
            hash_map[c]++;
        for (auto c : s)
            hash_map[c]--;
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it)
            if (it->second != 0)
                return it->first;
        return '*';
    }
};

int main(void) {
    return 0;
}
