#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// O(n^2 * logn) -> O(nlogn * longn) -> O(nlongn)
class Solution {
    int res = 0;

    void sort(vector<int>& nums, int i, int j) {
        if (i == j)
            return;
        int mid = (i + j) / 2;
        sort(nums, i, mid);
        sort(nums, mid + 1, j);
        merge(nums, i, mid + 1, j);
    }

    void merge(vector<int>& nums, int i, int j, int k) {
        vector<int> tmp(k - i + 1);
        int start0 = i, start1 = j, ind = 0;
        /*
        while (start0 < j || start1 <= k) {
            if (start0 == j) {
                tmp[ind++] = nums[start1++];
            }
            else if (start1 == k + 1) {
                tmp[ind++] = nums[start0++];
            }
            else if (nums[start0] < nums[start1]) {
                int target = floor(((double)nums[start0] - 1) / 2);
                res += (upper_bound(nums.begin() + start1, nums.begin() + k + 1, target) - nums.begin()) - start1;
                // for (int tmp = start1; tmp <= k; tmp++) {
                //     long long target = (long long)nums[tmp] * 2;
                //     if (nums[start0] > target)
                //         res++;
                //     else
                //         break;
                // }
                tmp[ind++] = nums[start0++];
            }
            else {
                long long target = (long long)nums[start1] * 2;
                res += j - (upper_bound(nums.begin() + start0, nums.begin() + j, target) - nums.begin());
                // for (int tmp = start0; tmp < j; tmp++) {
                //     if (nums[tmp] > target) {
                //         res += j - tmp;
                //         break;
                //     }
                // }
                tmp[ind++] = nums[start1++];
            }
        }
        */

        int pos = start1;
        while (start0 < j) {
            while (pos <= k && nums[start0] > (long long)nums[pos] * 2)
                pos++;
            res += pos - j;
            while (start1 <= k && nums[start1] < nums[start0])
                tmp[ind++] = nums[start1++];
            tmp[ind++] = nums[start0++];
        }
        while (start1 <= k)
            tmp[ind++] = nums[start1++];

        copy(tmp.begin(), tmp.end(), nums.begin() + i);
    }

public:
    int reversePairs(vector<int>& nums) {
        if (!nums.empty())
            sort(nums, 0, nums.size() - 1);
        return res;
    }
};

int main(void) {
    return 0;
}
