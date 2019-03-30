
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int search(vector<int>& nums, int target, int begin, int end) {
        if (begin == end)
            return -1;
        int mid = (begin + end) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target) {
            if (target >= nums[begin] && nums[mid] < nums[begin])
                return search(nums, target, begin, mid);
            return search(nums, target, mid + 1, end);
        }
        else {
            if (target < nums[begin] && nums[mid] > nums[end - 1])
                return search(nums, target, mid + 1, end);
            return search(nums, target, begin, mid);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size());
    }
};

int main(void) {
    vector<int> a = { 5, 1, 3 };
    cout << Solution().search(a, 0) << endl;
    return 0;
}
