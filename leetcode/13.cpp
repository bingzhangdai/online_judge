#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
    unordered_map<char, int> roman_char_to_int_{
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500},
        {'M', 1000}
    };
    unordered_map<char, char> subtract_roman_char_{
        {'V', 'I'}, {'X', 'I'},
        {'L', 'X'}, {'C', 'X'},
        {'D', 'C'}, {'M', 'C'}
    };
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length();) {
            if (i + 1 < s.length()) {
                auto next = subtract_roman_char_.find(s[i + 1]);
                if (next != subtract_roman_char_.end() && next->second == s[i]) {
                    res += roman_char_to_int_[s[i + 1]] - roman_char_to_int_[s[i]];
                    i += 2;
                    continue;
                }
            }
            res += roman_char_to_int_[s[i]];
            i++;
        }
        return res;
    }
};

int main(void) {
    cout << Solution().romanToInt("MCMXCIV") << endl;
    return 0;
}
