#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
                if (nums[j])
                    nums[i++] = nums[j];
        }
        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};

int main(void) {
    return 0;
}
