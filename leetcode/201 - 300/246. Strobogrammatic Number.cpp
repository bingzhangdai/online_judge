#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<int> upsidedown {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
public:
    bool isStrobogrammatic(string num) {
        auto n = num.length();
        for (auto i = 0; i <= n / 2; i++) {
            if (upsidedown[num[i] - '0'] != num[n - 1 - i] - '0')
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
