#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    void pivot(vector<int>& nums, int left, int right) {
        auto mid = (right + left) / 2;
        if (nums[left] < nums[right])
            swap(nums[left], nums[right]);
        if (nums[mid] < nums[right])
            swap(nums[mid], nums[right]);
        if (nums[left] > nums[mid])
            swap(nums[left], nums[mid]);
    }
    void kth_element(vector<int>& nums, int start, int end, int k) {
        if (end - start <= 5)
            return nth_element(nums.begin() + start, nums.begin() + start + k, nums.begin() + end, greater<>());
        auto left = start, right = end - 1;
        pivot(nums, left, right);
        auto p = nums[start];
        while (left <= right) {
            while (nums[left] > p)
                left++;
            while (nums[right] < p)
                right--;
            if (left <= right)
                swap(nums[left++], nums[right--]);
        }
        if (right - start < k)
            return kth_element(nums, left, end, k - left + start);
        else
            return kth_element(nums, start, left, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        kth_element(nums, 0, nums.size(), k - 1);
        return nums[k - 1];
    }
};

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        k = nums.size() - k + 1;
        for (int i = 0; i < k; i++)
            heap.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
            if (nums[i] < heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        return heap.top();
    }
};

int main(void) {
    vector<int> nums {3,2,1,5,6,4};
    cout << Solution().findKthLargest(nums, 5) << endl;
    return 0;
}
