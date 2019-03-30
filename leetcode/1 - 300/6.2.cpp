#include <iostream>
#include <string>
using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I     N
A   L S   I G
Y A   H R 
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        auto res = s;
        auto index = 0;
        auto interval = (numRows - 1) << 1;
        for (auto i = 0; i < numRows; i++) {
            auto mid = interval - (i << 1);
            for (auto j = i; j < s.length(); j += interval) {
                res[index++] = s[j];
                if (i && (numRows - i - 1) && j + mid < s.length()) {
                    res[index++] = s[j + mid];
                }
            }
        }
        return res;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.convert("PAYPALISHIRING", 4) << endl;

    return 0;
}
