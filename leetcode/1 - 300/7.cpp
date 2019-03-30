#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        bool sign = false;
        if (x < 0) {
            sign = true;
            x = -x;
        }
        long long out = 0;
        while (x) {
            out = out * 10 + x % 10;
            x /= 10;
        }
        if (sign)
            out = -out;
        if (out > INT_MAX || out < INT_MIN)
            return 0;
        return (int)out;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.reverse(-2147483648) << endl;

    system("pause");
    return 0;
}
