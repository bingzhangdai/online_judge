#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<int> alpha(26, 0);
        for (const auto c : s)
            alpha[c-'a']++;
        for (const auto c : t)
            if (--alpha[c-'a'] < 0)
                return false;
        return true;
    }
};

int main(void) {
    return 0;
}
