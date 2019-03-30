#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        vector<int> isprime(n, 1);
        isprime[0] = isprime[1] = 0;
        for (int i = 2; i * i < n; i++) {
            if (isprime[i]) {
                for (int j = i * i; j < n; j += i)
                    isprime[j] = 0;
            }
        }
        int res = 0;
        for (auto i : isprime)
            res += i;
        return res;
    }
};

int main(void) {
    return 0;
}
