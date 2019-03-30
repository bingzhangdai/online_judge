#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i  = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else
                nums1[k--] = nums2[j--];
        }
    }
};

int main(void) {
    vector<int> nums1 {1,4,6,0,0,0}, nums2 {2,5,7};
    Solution().merge(nums1, 3, nums2, 3);
    cout << nums1[3] << endl;
    // system("pause");
    return 0;
}
