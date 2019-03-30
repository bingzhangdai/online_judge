#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int bisearch(vector<int>& nums, int target, int left, int right) {
        if (left == right)
            if (nums[left] == target)
                return left;
            else
                return -1;
        int mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;
        if (nums[left] < nums[right])
            if (target < nums[mid])
                return bisearch(nums, target, left, mid);
            else
                return bisearch(nums, target, mid + 1, right);
        if (nums[mid] >= nums[left])
            if (target >= nums[left] && target <= nums[mid])
                return bisearch(nums, target, left, mid);
            else
                return bisearch(nums, target, mid + 1, right);
        else
            if (target >= nums[mid] && target <= nums[right])
                return bisearch(nums, target, mid + 1, right);
            else
                return bisearch(nums, target, left, mid);
    }
public:
    int search(vector<int>& nums, int target) {
        return bisearch(nums, target, 0, nums.size() - 1);
    }
};

int main(void) {
    vector<int> a = { 5, 1, 3 };
    cout << Solution().search(a, 0) << endl;
    system("pause");
    return 0;
}
