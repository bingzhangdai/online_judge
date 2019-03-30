#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bit = 1 << i, cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (bit & j) cnt1++;
                if (bit & nums[j]) cnt2++;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
