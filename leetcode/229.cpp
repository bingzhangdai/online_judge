#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0, n2 = 0, c1 = 0, c2 = 0;
        for (const auto n : nums) {
            if (n1 == n)
                c1++;
            else if (n2 == n)
                c2++;
            else if (c1 == 0) {
                n1 = n;
                c1++;
            }
            else if (c2 == 0) {
                n2 = n;
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for (const auto n : nums)
            if (n == n1)
                c1++;
            else if (n == n2)
                c2++;
        vector<int> res;
        if (c1 > nums.size() / 3)
            res.push_back(n1);
        if (c2 > nums.size() / 3)
            res.push_back(n2);
        return res;
    }
};

int main(void) {
    return 0;
}
