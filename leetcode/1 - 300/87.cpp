#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
    bool isContain(const string& s1, const string& s2) {
        map<char, int> count;
        for (auto c : s1) {
            auto pos = count.find(c);
            if (pos == count.end()) {
                count[c] = 1;
            }
            else {
                pos->second++;
            }
        }
        for (auto c : s2) {
            auto pos = count.find(c);
            if (pos == count.end() || --pos->second < 0)
                return false;
        }
        return true;
    }
public:
    bool isScramble(string s1, string s2) {
        auto n = s1.size();
        if (s1 == s2)
            return true;
        if (!isContain(s1, s2))
            return false;
        for (auto i = 1; i < n; i++) {
            auto s11 = s1.substr(0, i), s12 = s1.substr(i, n - i);
            auto s21 = s2.substr(0, i), s22 = s2.substr(i, n - i);
            auto t21 = s2.substr(0, n - i), t22 = s2.substr(n - i, i);
            if (isScramble(s11, s21) && isScramble(s12, s22) || isScramble(s12, t21) && isScramble(s11, t22))
                return true;
        }
        return false;
    }
};

int main(void) {
    cout << Solution().isScramble("rgtae", "great") << endl;
    // system("pause");
    return 0;
}
