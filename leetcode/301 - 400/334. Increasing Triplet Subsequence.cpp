#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX, j = INT_MAX;
        for (auto k : nums)
            if (k > j)
                return true;
            if (k <= i)
                i = k;
            else
                j = k;
        return false;
    }
};

int main(void) {
    return 0;
}
