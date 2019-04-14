#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for (auto num : nums) {
            if (num)
                sum++;
            else {
                res = max(sum, res);
                sum = 0;
            }
        }
        return max(sum, res);
    }
};

int main(void) {
    return 0;
}
