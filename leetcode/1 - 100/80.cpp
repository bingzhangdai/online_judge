#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto left = 0, right = 0;
        while (right < nums.size()) {
            if (right + 1 < nums.size() && nums[right] == nums[right + 1]) {
                nums[left++] = nums[right];
                nums[left++] = nums[right];
            }
            else {
                nums[left++] = nums[right];
            }
            while (++right < nums.size() && nums[right] == nums[right - 1]);
        }
        return left;
    }
};


int main(void) {
    vector<int> nums = {-3,-3,-2,-1,-1,0,0,0,0,0};
    cout << Solution().removeDuplicates(nums) << endl;
    // system("pause");
    return 0;
}
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array nums = [1,1,1,2,2,3], 
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length. 
*/