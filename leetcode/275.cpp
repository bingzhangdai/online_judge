#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size() - 1, n = citations.size(), h = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (n - mid <= citations[mid]) {
                h = max(h, n - mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return h;
    }
};

int main(void) {
    return 0;
}
