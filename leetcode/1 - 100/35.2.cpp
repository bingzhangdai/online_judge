#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int search(vector<int>& nums, int target, int begin, int end) {
        if (begin == end)
            return begin + (begin < nums.size() && nums[begin] < target ? 1 : 0);
        int mid = (begin + end) >> 1;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return search(nums, target, mid + 1, end);
        return search(nums, target, begin, mid);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size());
    }
};

int main(void) {
    vector<int> a = { 1, 3, 5, 6 };
    cout << Solution().searchInsert(a, 0) << endl;
    return 0;
}
