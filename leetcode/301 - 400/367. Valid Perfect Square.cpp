#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num / 2 + 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            long res = (long)num - (long)mid * mid;
            if (res > 0)
                left = mid + 1;
            else if (res < 0)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};

int main(void) {
    return 0;
}
