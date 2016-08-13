#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    inline double abs(double m, double n) {
        return (m > n) ? (m - n) : (n - m);
    }
public:
    int mySqrt(int x) {
        double res(x), pre(0);
        while (abs(res, pre) > 0.5) {
            pre = res;
            res = res / 2 + 1.0*x / (2*res);
        }
        return (int)res;
    }
};

int main(void) {
    cout << Solution().mySqrt(99) << endl;
    // system("pause");
    return 0;
}
