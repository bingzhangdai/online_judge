#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    set<int> hash_map;
public:
    Solution() {
        for (int i = 0; i < 32; i += 2) {
            hash_map.insert(1 << i);
        }
    }
    bool isPowerOfFour(int num) {
        return hash_map.find(num) != hash_map.end();
    }
};

int main(void) {
    return 0;
}
