#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        while (n != 1) {
            if (nums.find(n) != nums.end())
                return false;
            nums.insert(n);
            int res = 0;
            do
                res += (n % 10) * (n % 10);
            while (n /= 10);
            n = res;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
