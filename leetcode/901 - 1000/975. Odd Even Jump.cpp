#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

/*
During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
*/

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<bool> odd(n, false), even(n, false);
        map<int, int> nums{ {A.back(), n - 1} };
        odd[n - 1] = even[n - 1] = true;
        for (auto i = n - 2; i >= 0; i--) {
            auto it = nums.lower_bound(A[i]);
            if (it != nums.end())
                odd[i] = even[it->second];
            if (it == nums.end() || it->first > A[i] && it != nums.begin())
                --it;
            if (it->first <= A[i])
                even[i] = odd[it->second];
            nums[A[i]] = i;
        }
        return accumulate(odd.begin(), odd.end(), 0);
    }
};

int main(void) {
    return 0;
}
