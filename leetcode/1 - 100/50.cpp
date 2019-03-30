#include <iostream>
using namespace std;

class Solution {
    double myPow2(double x) {
        return x * x;
    }
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) {
                x *= x;
                n++;
            }
                n = -n;
        }
        if (n % 2)
            return myPow2(myPow(x, (n - 1) / 2)) * x;
        else
            return myPow2(myPow(x, n / 2));
    }
};

int main(void) {
    cout << Solution().myPow(2.00000, -2147483648) << endl;
    // system("pause");
    return 0;
}
