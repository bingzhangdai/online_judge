#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        for (const auto n : nums) {
            uint32_t p = 0b1;
            int bit_count = 0;
            do {
                if (n & p)
                    bits[bit_count]++;
                bit_count++;
            } while (p <<= 1);
        }
        int res = 0, p = 0b1;
        for (const auto b : bits) {
            if (b % 3)
                res |= p;
            p <<= 1;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
/*
Given an array of integers, every element appears three times except for one. Find that single one. 
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
