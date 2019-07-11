#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        set<int> bs;
        for (auto i = 0; i < bulbs.size(); i++) {
            auto pos = bs.upper_bound(bulbs[i]);
            if (pos != bs.end() && *pos - bulbs[i] - 1 == K)
                return i + 1;
            if (pos != bs.begin() && bulbs[i] - *--pos - 1 == K)
                return i + 1;
            bs.insert(pos, bulbs[i]);
        }
        return -1;
    }
};

int main(void) {
    return 0;
}
