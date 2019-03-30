#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

// O(32n) is trivial
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        // i = (i >> 1 << 1) + (i & 1)
        for (int i = 1; i <= num; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
