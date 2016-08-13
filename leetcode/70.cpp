#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a(1), b(2), res;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        for (int i = 3; i <= n; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};

int main(void) {
    cout << Solution().climbStairs(5) << endl;
    // system("pause");
    return 0;
}
