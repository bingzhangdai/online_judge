#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0;
        int m = num1.size(), n = num2.size();
        for (int i = 0; i < m || i < n; i++) {
            if (i < m)
                carry += num1[m - i - 1] - '0';
            if (i < n)
                carry += num2[n - i - 1] - '0';
            res.append(1, carry % 10 + '0');
            carry /= 10;
        }
        if (carry)
            res.append(1, carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(void) {
    return 0;
}
