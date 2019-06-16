#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (auto i : s)
            count[i]++;
        for (auto i = 0; i < s.length(); i++)
            if (count[s[i]] == 1)
                return i;
        return -1;
    }
};

int main(void) {
    return 0;
}
