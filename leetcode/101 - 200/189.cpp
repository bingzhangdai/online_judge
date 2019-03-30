#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end() - k%n);
        reverse(nums.end() - k%n, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main(void) {
    return 0;
}
