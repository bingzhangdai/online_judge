#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 0;
        if (n == 0)
            return 1;
        for (int i = 0; i < n && i < 10; i++) {
            if (i == 0)
                res += 10;
            else {
                int tmp = 1;
                for (int k = 0; k <= i; k++) {
                    tmp *= (k == 0 ? 9 : (10 - k));
                }
                res += tmp;
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
