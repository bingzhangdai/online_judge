#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 16ms
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// 25ms
class Solution {
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
