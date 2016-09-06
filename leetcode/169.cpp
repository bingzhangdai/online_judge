#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem, times = 0;
        for (const auto n : nums) {
            if (times == 0) {
                elem = n;
                times++;
            }
            else
                times += elem == n ? 1 : -1;
        }
        return elem;
    }
};

int main(void) {
    return 0;
}
