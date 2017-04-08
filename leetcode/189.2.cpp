#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int gcd(int m, int n) {
        int tmp;
        while (tmp = m % n) {
            m = n;
            n = tmp;
        }
        return n;
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (!(k %= n))
            return;
        int num_orbit = gcd(n, k);
        for (int i = 0; i < num_orbit; i++) {
            int j = (i + k) % n;
            int tmp = nums[i];
            while (j != i) {
                swap(tmp, nums[j]);
                j = (j + k) % n;
            }
            nums[j] = tmp;
        }
    }
};

int main(void) {
    return 0;
}
