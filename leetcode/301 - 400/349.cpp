#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int moveNext(vector<int>& nums, int i) {
        while (i < nums.size() - 1 && nums[i + 1] == nums[i])
            i++;
        return i + 1;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort (nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i = moveNext(nums1, i);
                j = moveNext(nums2, j);
            }
            else if (nums1[i] < nums2[j])
                i = moveNext(nums1, i);
            else
                j = moveNext(nums2, j);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
