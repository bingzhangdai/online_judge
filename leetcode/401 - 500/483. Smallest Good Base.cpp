#include <iostream>
#include <vector>
using namespace std;

const int SMALL = 0;
const int LARGE = 1;
const int EQUAL = 3;

class Solution {
public:
    // (k^(m+1) - 1) / (k - 1) = k^m + (k^m - 1)/(k - 1) = n;
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        int m = 0;
        while (true) {
            if (((long long)1 << m) - 1 < num && num < ((long long)1 << m + 2) - 1)
                break;
            m++;
        }
        auto cmp = [](int k, int m, long long target) -> int {
            if ((to_string(k).length() - 1) * m + 1 > to_string(target).length())
                return LARGE;
            unsigned long long k_to_the_m = 1;
            long long res = 1;
            for (int i = 0; i < m; i++) {
                // possible overflow
                if (LONG_MAX / k_to_the_m < k)
                    return LARGE;
                k_to_the_m *= k;
                res = k_to_the_m + (k_to_the_m - 1) / (k - 1);
                if (res > target)
                    return LARGE;
            }
            if (res > target)
                return LARGE;
            if (res < target)
                return SMALL;
            return EQUAL;
        };
        for (int exp = m; exp > 1; exp--) {
            int left = 2, right = 1E9;
            while (left <= right) {
                int mid = (right - left) / 2 + left;
                switch (cmp(mid, exp, num)) {
                    case SMALL:
                        left = mid + 1;
                        break;
                    case LARGE:
                        right = mid - 1;
                        break;
                    case EQUAL:
                    default:
                        return to_string(mid);
                }
            }
        }
        // m == 1
        return to_string(num - 1);
    }
};

int main(void) {
    return 0;
}
