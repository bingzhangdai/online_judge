#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int index, min_i;
        for (index = nums.size() - 1; index > 0; index--) {
            if (nums[index] > nums[index - 1])
                break;
        }
        min_i = index;
        for (int i = index + 1; i < nums.size(); i++)
            if (nums[i] < nums[min_i] && nums[i] > nums[index - 1])
                min_i = i;
        if (index == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        swap(nums[index - 1], nums[min_i]);
        sort(nums.begin() + index, nums.end());
    }
};

int main(void) {
    auto p = vector<int>({ 2,3,1 });
    Solution().nextPermutation(p);
    cout << p[0] << p[1] << p[2] << endl;
    system("pause");
    return 0;
}
