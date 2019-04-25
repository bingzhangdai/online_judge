#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
*/

class Solution {
    int num_of_smaller_or_equal(const vector<int>& line, int num, int& target) {
        auto it = upper_bound(line.begin(), line.end(), num);
        if (it == line.begin())
            target = INT_MIN;
        else
            target = *(it - 1);
        return it - line.begin();
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix.front().size();
        int left = matrix[0][0], right = matrix[m - 1][n - 1];
        while (left <= right) {
            int count = 0;
            int mid = (right - left) / 2 + left;
            int target, res = INT_MIN;
            for (const auto& line : matrix) {
                count += num_of_smaller_or_equal(line, mid, target);
                res = max(res, target);
            }
            if (left == right)
                return res;
            if (count > k)
                right = mid;
            else if (count < k)
                left = mid + 1;
            else
                return res;
        }
        return -1;
    }
};

int main(void) {
    return 0;
}
