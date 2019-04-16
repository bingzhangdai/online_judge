#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    bool isRepeated(const string& s, int len) {
        auto res = s.substr(0, len);
        int pos = len;
        while (true) {
            if (pos == s.length())
                return true;
            if (s.find(res, pos) != pos)
                return false;
            pos += len;
        }
    }
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (int i = s.length() / 2; i > 0; i--) {
            if (s.length() % i == 0 && isRepeated(s, i)) {
                return true;
            }
        }
        return false;
    }
};

int main(void) {
    return 0;
}
