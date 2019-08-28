#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long l = lower;
        for (auto n : nums) {
            if (n == l + 1)
                res.push_back(to_string(l));
            if (n > l + 1)
                res.push_back(to_string(l) + "->" + to_string(n - 1));
            l = (long)n + 1;
        }
        if (l == upper)
            res.push_back(to_string(l));
        else if (l < upper)
            res.push_back(to_string(l) + "->" + to_string(upper));
        return res;
    }
};

int main(void) {
    return 0;
}
