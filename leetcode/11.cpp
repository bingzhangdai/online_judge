#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximum = 0;
        int i(0), j(height.size() - 1);
        while (i <= j) {
            int area = (j - i) * min(height[i], height[j]);
            if (maximum < area)
                maximum = area;
            if (height[i] < height[j]) {
                int k = i + 1;
                while (k < height.size() && height[k] < height[i]) { k++; }
                i = k;
            }
            else {
                int k = j - 1;
                while (k >= 0 && height[k] < height[j]) { k--; }
                j = k;
            }
        }
        return maximum;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.maxArea(vector<int>({ 1,2,3 })) << endl;

    system("pause");
    return 0;
}
