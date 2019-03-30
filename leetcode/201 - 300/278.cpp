#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l <= r) {
            if (l == r)
                return l;
            int mid = (r - l) / 2 + l;
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return n;
    }
};

int main(void) {
    return 0;
}
