#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0, m = a.size(), n = b.size();
        for (int i = 0; i < m || i < n; i++) {
            if (i < m)
                carry += a[m - i - 1] - '0';
            if (i < n)
                carry += b[n - i - 1] - '0';
            res.insert(0, 1, carry % 2 + '0');
            carry /= 2;
        }
        if (carry)
            res.insert(0, 1, carry + '0');
        return res;
    }
};

int main(void) {
    cout << Solution().addBinary("11", "1") << endl;
    // system("pause");
    return 0;
}
