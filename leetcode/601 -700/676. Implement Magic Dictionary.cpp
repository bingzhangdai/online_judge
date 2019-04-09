#include <iostream>
#include <vector>
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
        if (m < n)
            swap(m, n);
        int ind = 1;
        while (ind <= m - 1 && k - ind >= 0) {
            k -= ind;
        }
        while (ind <= n && k - ind >= 0) {
            k -= ind;
        }
    }
};

int main(void) {
    return 0;
}
