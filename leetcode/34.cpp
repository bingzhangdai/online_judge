#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int find_first(vector<int>& nums, int target, int left, int right) {
        if (left == right)
            if (nums[left] == target)
                return left;
            else
                return -1;
        int mid = (left + right) / 2;
        if (target <= nums[mid])
            return find_first(nums, target, left, mid);
        else
            return find_first(nums, target, mid + 1, right);
    }
    int find_last(vector<int>& nums, int target, int left, int right) {
        if (left == right)
            if (nums[left] == target)
                return left;
            else
                return -1;
        int mid = (left + right) / 2;
        if (target >= nums[mid])
            if (target >= nums[mid + 1])
                return find_last(nums, target, mid + 1, right);
            else if (target == nums[mid])
                return mid;
            else
                return -1;
        else
            return find_last(nums, target, left, mid);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int b = find_first(nums, target, 0, nums.size() -1);
        res.push_back(b);
        int e = find_last(nums, target, 0, nums.size() - 1);
        res.push_back(e);
        return res;
    }
};

int main(void) {
    vector<int> a = { 5, 7, 7, 8, 8, 10 };
    cout << Solution().searchRange(a, 8)[1] << endl;
    system("pause");
    return 0;
}
