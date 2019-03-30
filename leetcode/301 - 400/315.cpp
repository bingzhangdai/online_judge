#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> res;
    void mergeSort(vector<pair<int, int>>& nums, int left, int right) {
        if (left == right)
            return;
        int mid = (left + right) / 2 + 1;
        mergeSort(nums, left, mid - 1);
        mergeSort(nums, mid, right);
        vector<pair<int, int>> tmp(right - left + 1, pair<int, int>(0, 0));
        int i = left, j = mid;
        for (int k = 0; k < tmp.size(); k++) {
            if (i > mid - 1) {
                tmp[k] = nums[j++];
            }
            else if (j > right) {
                tmp[k] = nums[i++];
            }
            else if (nums[i].first > nums[j].first) {
                for (int l = i; l < mid; l++)
                    res[nums[l].second]++;
                tmp[k] = nums[j++];
            }
            else {
                tmp[k] = nums[i++];
            }
        }
        for (auto num : tmp)
            nums[left++] = num;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n) {
            res.resize(n);
            vector<pair<int, int>> nums_new;
            nums_new.reserve(n);
            for (int i = 0; i < n; i++)
                nums_new.emplace_back(nums[i], i);
            mergeSort(nums_new, 0, nums.size() - 1);
        }
        return res;
    }
};

int main(void) {
    return 0;
}