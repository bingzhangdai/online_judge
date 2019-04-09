#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example 1:
Input: a = 2, b = [3]
Output: 8
Example 2:
Input: a = 2, b = [1,0]
Output: 1024
*/



class Solution {
    const int mod = 1337;
    int pow(int a, int b) {
        if (b == 0)
            return 1;
        int res = pow(a, b / 2);
        res = res * res % mod;
        if (b & 1)
            res = res * a % mod;
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        a = a % mod;
        int res = 1;
        for (auto num : b) {
            res = pow(res, 10) * pow(a, num) % mod;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
