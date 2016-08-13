#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res = string(num2.length() + num1.length(), '0');
        for (int i = num1.length() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.length() - 1; j >= 0; j--) {
                int pos = res.length() - num1.length() - num2.length() + 1 + i + j;
                int mul = (num2[j] - '0') * (num1[i] - '0') + carry + res[pos] - '0';
                carry = mul / 10;
                res[pos] = (mul % 10) + '0';
            }
            for (int k = res.length() - num1.length() - num2.length() + i; carry != 0; k--) {
                int mul = carry + res[k] - '0';
                res[k] = mul % 10 + '0';
                carry = mul / 10;
            }
        }
        int pos = 0;
        while (pos < res.length() && res[pos] == '0') pos++;
        if (pos == res.length())
            return "0";
        res = res.substr(pos, res.length() - pos);
        return res;
    }
};

int main(void) {
    cout << Solution().multiply("0099", "01") << endl;
    system("pause");
    return 0;
}
