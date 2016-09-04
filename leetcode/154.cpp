#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[left] < nums[right]) {
                right = mid;
            }
            else if (nums[left] > nums[right]) {
                if (nums[mid] >= nums[left])
                    left = mid + 1;
                else
                    right = mid;
            }
            else
                left++;
        }
        return nums[left];
    }
};

int main(void) {
    vector<int> nums {4, 5, 6, 7, 0, 0, 1, 2, 4};
    cout << Solution().findMin(nums) << endl;
    return 0;
}
