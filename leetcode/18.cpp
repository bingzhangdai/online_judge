#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    int getnextindex(vector<int>& nums, int i) {
        int j = i;
        while (j < nums.size() && nums[j] == nums[i]) { j++; }
        return j;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = vector<vector<int>>();
        int i(0), j, m, n;
        while (i < nums.size()) {
            j = i + 1;
            while(j < nums.size()) {
                m = j + 1;
                n = nums.size() - 1;
                while (m < n) {
                    int diff = nums[i] + nums[j] + nums[m] + nums[n] - target;
                    if (diff == 0)
                        res.push_back(vector<int>({ nums[i], nums[j], nums[m], nums[n] }));
                    if (diff <= 0)
                        m = getnextindex(nums, m);
                    else {
                        int k = n;
                        while (k >= 0 && nums[k] == nums[n]) { k--; }
                        n = k;
                    }
                }
                j = getnextindex(nums, j);
            }
            i = getnextindex(nums, i);
            
        }
        return res;
    }
};

int main(void) {
    cout << Solution().fourSum(vector<int>({ -1,0,-1,0,-2,2 }), 0).size() << endl;

    system("pause");
    return 0;
}
