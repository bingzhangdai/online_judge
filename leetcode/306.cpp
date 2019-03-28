#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    string add(const string& num, int start1, int end1, int start2, int end2) {
        int m = end1 - start1 + 1, n = end2 - start2 + 1;
        int len = max(m, n) + 1, carry = 0;
        string res(len, '0');
        for (int i = 0; i < m; i++)
            res[len - i - 1] = num[m - i + start1 - 1];
        for (int i = 0; i < len; i++) {
            int tmp = res[len - i - 1] - '0' + (i < n ? num[n - i + start2 - 1] - '0' : 0) + carry;
            res[len - i - 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        return res[0] == '0' ? res.substr(1, len - 1) : res;
    }
    bool isAdditive(const string& num, int start1, int end1, int start2, int end2) {
        while (true) {
            string sum = add(num, start1, end1, start2, end2);
            if (num.length() - end2 - 1 < sum.length())
                return false;
            for (int i = 0; i < sum.length(); i++)
                if (num[end2 + 1 + i] != sum[i])
                    return false;
            if (num.length() - end2 - 1 == sum.length())
                return true;
            start1 = start2;
            end1 = end2;
            start2 = end2 + 1;
            end2 = end2 + sum.length();
        }
    }
    inline bool isNum(const string& num, int start, int end) {
        return end - start == 0 || num[start] != '0';
    }
public:
    bool isAdditiveNumber(string num) {
        for (int end1 = 0; end1 < num.length(); end1++) {
            for (int end2 = end1 + 1; end2 < num.size(); end2++) {
                if (isNum(num, 0, end1) && isNum(num, end1 + 1, end2) && isAdditive(num, 0, end1, end1 + 1, end2))
                    return true;
            }
        }
        return false;
    }
};

int main(void) {
    return 0;
}
