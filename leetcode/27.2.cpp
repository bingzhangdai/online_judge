#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (auto num : nums) {
            if (num != val) {
                nums[i++] = num;
            }
        }
        return i;
    }
};

int main(void) {
    cout << Solution().removeElement(vector<int>({3, 2, 2, 3}), 3) << endl;
    return 0;
}
