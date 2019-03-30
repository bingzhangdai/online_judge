#include <iostream>
#include <vector>
#include <math>
using namespace std;

// LTE
/*
class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int num_switch = 0;
            for (int k = 1; k <= i; k++) {
                if (i % k == 0)
                    num_switch++;
            }
            res += (num_switch & 1);
        }
        return res;
    }
};
*/
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(void) {
    return 0;
}
