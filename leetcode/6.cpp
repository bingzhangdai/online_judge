#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string out = "";
        if (numRows == 1)
            return s;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j += (numRows - 1) * 2) {
                out += s[j];
                if (i != 0 && i != numRows - 1 && (numRows - i - 1) * 2 + j < s.length())
                    out += s[(numRows - i - 1) * 2 + j];
            }
        }
        return out;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.convert("A", 1) << endl;

    system("pause");
    return 0;
}
