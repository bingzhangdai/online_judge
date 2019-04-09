#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

/*
Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3 
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
*/

class Solution {
    vector<int> res;

    vector<int> maxSubArray(const vector<int>& nums, int len) {
        vector<int> res;
        deque<int> stack;
        for (int i = 0; i < nums.size() - len; i++) {
            while (!stack.empty() && *stack.rbegin() < nums[i])
                stack.pop_back();
            stack.push_back(nums[i]);
        }
        for (int i = nums.size() - len; i < nums.size(); i++) {
            while (!stack.empty() && stack.back() < nums[i])
                stack.pop_back();
            stack.push_back(nums[i]);
            res.push_back(stack[0]);
            stack.pop_front();
        }
        return res;
    }

    void merge(const vector<int>& nums1, const vector<int>& nums2) {
        bool flag = false;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while (i < m || j < n) {
            int whichone;
            if (i == m || nums1[i] < nums2[j])
                whichone = 2;
            else if (j == n || nums1[i] > nums2[j])
                whichone = 1;
            else {
                int k = 0;
                while (i + k < m && j + k < n && nums1[i + k] == nums2[j + k])
                    k++;
                if (i + k == m)
                    whichone = 2;
                else if (j + k == n)
                    whichone = 1;
                else if (nums1[i + k] > nums2[j + k])
                    whichone = 1;
                else
                    whichone = 2;
            }
            if (whichone == 1) {
                if (!flag && nums1[i] < res[i + j])
                    return;
                if (nums1[i] > res[i + j]) {
                    flag = true;
                }
                res[i + j] = nums1[i++];
            }
            else {
                if (!flag && nums2[j] < res[i + j])
                    return;
                if (nums2[j] > res[i + j]) {
                    flag = true;
                }
                res[i + j] = nums2[j++];
            }
        }
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0)
            return res;
        res.resize(k, INT_MIN);
        int t = k - nums2.size();
        auto start = max(0, (int)(k - nums2.size())), end = min(k, (int)(nums1.size()));
        for (int i = start; i <= end; i++)
            merge(maxSubArray(nums1, i), maxSubArray(nums2, k - i));
        return res;
    }
};

int main(void) {
    return 0;
}
