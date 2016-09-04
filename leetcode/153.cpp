#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[right] < nums[left]) {
                if (nums[mid] >= nums[left])
                    left = mid + 1;
                else
                    right = mid;
            }
            else
                right = mid;
        }
        return nums[left];
    }
};

int main(void) {
    vector<int> nums {4, 5, 6, 7, 0, 1, 2};
    cout << Solution().findMin(nums) << endl;
    return 0;
}
