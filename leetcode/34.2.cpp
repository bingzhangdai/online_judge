#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int searchStart(vector<int>& nums, int target, int begin, int end) {
        if (begin == end)
            return -1;
        int mid = (begin + end) / 2;
        if (nums[begin] == target)
            return begin;
        if (nums[mid] >= target)
            return searchStart(nums, target, begin + 1, mid + 1);
        return searchStart(nums, target, mid + 1, end);
    }
    int searchEnd(vector<int>& nums, int target, int begin, int end) {
        if (begin == end)
            return -1;
        int mid = (begin + end) / 2;
        if (nums[end - 1] == target)
            return end - 1;
        if (nums[mid] <= target)
            return searchEnd(nums, target, mid, end - 1);
        return searchEnd(nums, target, begin, mid);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return { searchStart(nums, target, 0, nums.size()),
                searchEnd(nums, target, 0, nums.size()) };
    }
};

int main(void) {
    vector<int> a = { 5, 7, 7, 8, 8, 10 };
    cout << Solution().searchRange(a, 8)[1] << endl;
    return 0;
}
