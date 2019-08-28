#include <iostream>
#include <vector>
#include <math>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (auto j : J)
            jewels.insert(j);
        auto res = 0;
        for (auto s : S)
            res += jewels.count(s);
        return res;
    }
};

int main(void) {
    return 0;
}
