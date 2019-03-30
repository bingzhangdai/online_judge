#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++)
            res[i] = nums[i-1] * res[i-1];
        int product = 1;
        for (int i = n - 2; i >= 0; i--) {
            product *= nums[i+1];
            res[i] *= product;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
