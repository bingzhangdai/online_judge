#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, i = 0, j = 0, sum = 0;
        while (j < nums.size()) {
            sum += nums[j++];
            if (sum >= s) {
                while ((sum -= nums[i++]) >= s);
                if (j - i + 1 < res)
                    res = j - i + 1;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main(void) {
    return 0;
}
