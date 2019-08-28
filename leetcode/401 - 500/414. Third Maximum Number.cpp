#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Solution {
    const int k = 3;
public:
    int thirdMax(vector<int>& nums) {
        list<int> arr;
        for (auto n : nums) {
            auto it = upper_bound(arr.begin(), arr.end(), n);
            if (it != arr.begin() && prev(it) != arr.end() && *prev(it) == n)
                continue;
            arr.insert(it, n);
            if (arr.size() > k)
                arr.pop_front();
        }
        return arr.size() == k ? arr.front() : arr.back();
    }
};

/*
// Note that the third maximum here means the third maximum distinct number.
class Solution {
    const int k = 3;
public:
    int thirdMax(vector<int>& nums) {
        auto pos = (nums.size() >= k ? k : 1) - 1;
        return nth_element(nums.begin(), nums.begin() + pos, nums.end(), greater<>()), nums[pos];
    }
};
*/

int main(void) {
    return 0;
}
