#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (const auto c : s) {
            res *= 26;
            res += c - 'A' + 1;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
