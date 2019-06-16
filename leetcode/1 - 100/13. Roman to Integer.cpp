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
        for (int i = s.length(); i >= 0; i--) {
            res += roman_char_to_int_[s[i]];
            if (i - 1 >= 0 && subtract_roman_char_[s[i]] == s[i - 1]) {
                res -= roman_char_to_int_[s[i - 1]];
                i--;
            }
        }
        return res;
    }
};

int main(void) {
    cout << Solution().romanToInt("MCMXCIV") << endl;
    return 0;
}
