#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int begin(0), end(0);
        int sign = 1;
        while (str[begin] == ' ' && begin < str.length())
            begin++;
        // constains only whitespace characters
        if (begin == str.length())
            return 0;
        if (str[begin] == '+')
            begin++;
        else if (str[begin] == '-') {
            begin++;
            sign = -1;
        }
        for (end = begin; end <= str.length(); end++)
            if (str[end] < '0' || str[end] > '9')
                break;
        // not valid
        if (begin == end)
            return 0;
        string out = str.substr(begin, end - begin);
        long long ago = 0;
        // exceed 64-bit (i < 12)
        for (int i = 0; i < out.length() && i < 12; i++)
            ago = ago * 10 + out[i] - '0';
        ago *= sign;
        if (ago > INT_MAX)
            return INT_MAX;
        if (ago < INT_MIN)
            return INT_MIN;
        return (int)ago;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.myAtoi("9223372036854775809") << endl;

    system("pause");
    return 0;
}
