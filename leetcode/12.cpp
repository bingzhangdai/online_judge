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
    const string roman_chars = "MDCLXVI";
public:
    string intToRoman(int num) {
        string res = "";
        for (char roman : roman_chars) {
            auto subtract_char = subtract_roman_char_.find(roman);
            auto subtract_num = subtract_char != subtract_roman_char_.end() ? roman_char_to_int_[subtract_char->second] : 0;
            auto roman_num = roman_char_to_int_[roman];
            while (num / roman_num) {
                res += roman;
                num -= roman_num;
            }
            if ((num + subtract_num) / roman_num) {
                res = res + subtract_char->second + roman;
                num -= (roman_num - subtract_num);
            }
        }
        return res;
    }
};


int main(void) {
    cout << Solution().intToRoman(290) << endl;
    return 0;
}
