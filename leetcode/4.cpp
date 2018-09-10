#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
    double findMedianSortedArrays(const vector<int>& nums1, int start1, int end1, const vector<int>& nums2, int start2, int end2, int k) {
        if(end1 - start1 > end2 - start2) {
            return findMedianSortedArrays(nums2, start2, end2, nums1, start1, end1, k);
        }

        if (start1 == end1) {
            return nums2[start2 + k - 1];
        }

        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }

        auto mid1(min(k / 2, end1 - start1) + start1);
        auto mid2(min(k / 2, end2 - start2) + start2);
        if (nums1[mid1 - 1] < nums2[mid2 - 1]) {
            return findMedianSortedArrays(nums1, mid1, end1, nums2, start2, end2, k - (mid1 - start1));
        }
        else {
            return findMedianSortedArrays(nums1, start1, end1, nums2, mid2, end2, k - (mid2 - start2));
        }
    }
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        auto total = nums1.size() + nums2.size();
        return total & 1 
            ? findMedianSortedArrays(nums1, 0, nums1.size(), nums2, 0, nums2.size(), total / 2 + 1)
            : 0.5 * (findMedianSortedArrays(nums1, 0, nums1.size(), nums2, 0, nums2.size(), total / 2) 
                + findMedianSortedArrays(nums1, 0, nums1.size(), nums2, 0, nums2.size(), total / 2 + 1));
    }
};

int main(void) {
    auto s = Solution();
    cout << s.findMedianSortedArrays({ 1, 2 }, { 3, 4 }) << endl;

    return 0;
}
