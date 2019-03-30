#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res = string(num1.size() + num2.size(), '0');
        int carry;
        for (int i = 0; i < num1.size(); i++) {
            carry = 0;
            for (int j = 0; j < num2.size(); j++) {
                int val = (num1[num1.size() - i - 1] - '0')
                        * (num2[num2.size() - j - 1] - '0')
                        + res[res.size() - i - j - 1] - '0'
                        + carry;
                res[res.size() - i - j - 1] = val % 10 + '0';
                carry = val / 10;
            }
            if (carry) {
                res[res.size() - i - num2.size() - 1] = carry + '0';
            }
        }
        return (num1 == "0" || num2 == "0") ? "0" : carry ? res : res.substr(1, res.length() - 1);
    }
};

int main(void) {
    cout << Solution().multiply("99", "1") << endl;
    return 0;
}
