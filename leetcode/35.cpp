#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int search(vector<int>& nums, int target, int left, int right) {
        if (left == right)
            if (target <= nums[left])
                return left;
            else
                return left + 1;
        int mid = (left + right) / 2;
        if (target <= nums[mid])
            return search(nums, target, left, mid);
        else
            return search(nums, target, mid + 1, right);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};

int main(void) {
    vector<int> a = { 1, 3, 5, 6 };
    cout << Solution().searchInsert(a, 0) << endl;
    system("pause");
    return 0;
}
