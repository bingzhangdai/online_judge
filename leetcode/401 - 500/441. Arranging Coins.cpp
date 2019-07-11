#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        for (long i = 0;;i++) {
            if (i * (i + 1) / 2 <= n && (i + 1) * (i + 2) / 2 > n)
                return i;
        }
    }
};

int main(void) {
    return 0;
}
