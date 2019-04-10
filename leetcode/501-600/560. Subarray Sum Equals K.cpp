#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> hash_map;
        hash_map[0] = 1;
        for (auto num : nums) {
            sum += num;
            auto target = sum - k;
            res += hash_map[target];
            hash_map[sum]++;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
