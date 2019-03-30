#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[left] < nums[right]) {
                if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if (nums[left] > nums[right]) {
                if (nums[mid] >= nums[left]) {
                    if (target >= nums[left] && target < nums[mid])
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                else {
                    if (target >= nums[mid] && target <= nums[right])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
            else {
                left++;
            }
        }
        return false;
    }
};


int main(void) {
    vector<int> nums {4, 1, 2, 3, 3, 3, 4, 4};
    cout << Solution().search(nums, 2) << endl;
    // system("pause");
    return 0;
}
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*/
