#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int max_height = 0;
        for (int i = 0; i < height.size(); i++)
            if (height[i] > height[max_height])
                max_height = i;
        int res = 0, cur_height = height[0];
        for (int left = 0; left < max_height; left++) {
            if (cur_height < height[left])
                cur_height = height[left];
            res += cur_height - height[left];
        }
        cur_height = height[height.size() - 1];
        for (int right = height.size() - 1; right > max_height; right--) {
            if (cur_height < height[right])
                cur_height = height[right];
            res += cur_height - height[right];
        }
        return res;
    }
};

int main(void) {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << Solution().trap(height) << endl;
    system("pause");
    return 0;
}
