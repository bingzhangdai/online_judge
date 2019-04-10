#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
Example 1:
Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).

Example 2:
Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (right - left) / 2 + left, cnt = 0;
            for (int i = 1; i <= m; i++) {
                if (i * n <= mid)
                    cnt += n;
                else
                    cnt += mid / i;
            }
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main(void) {
    return 0;
}
