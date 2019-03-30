#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        auto bit = 0;
        for (auto i : nums)
            bit ^= i;
        bit = bit & (~(bit - 1));
        vector<int> res(2, 0);
        for (auto i : nums)
            res[i & bit ? 0 : 1] ^= i;
        return res;
    }
};

int main(void) {
    return 0;
}
