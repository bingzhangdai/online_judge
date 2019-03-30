#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, j = 0;
        while (i < nums.size()) {
            for (j = i + 1; j < nums.size() && nums[j] - nums[j - 1] == 1; j++);
            string s = to_string(nums[i]);
            if (j != i + 1)
                s += "->" + to_string(nums[j-1]);
            res.push_back(s);
            i = j;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
/*
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/
