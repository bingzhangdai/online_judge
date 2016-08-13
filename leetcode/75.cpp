#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right && nums[left] == 0)
            left++;
        while (right >= left && nums[right] == 2)
            right--;
        for (int i = left; i <= right;) {
            if (nums[i] == 0)
                swap(nums[left++], nums[i++]);
            else if (nums[i] == 2)
                swap(nums[right--], nums[i]);
            else
                i++;
        }
    }
};

int main(void) {
    vector<int> nums {0, 1, 1, 2, 0, 1};
    Solution().sortColors(nums);
    for_each(nums.begin(), nums.end(), [](int i) { cout << i << endl; });
    // system("pause");
    return 0;
}
