#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int res = 0;
       for (auto i : nums)
           res ^= i;
       return res;
    }
};

int main(void) {
    return 0;
}
/*
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
