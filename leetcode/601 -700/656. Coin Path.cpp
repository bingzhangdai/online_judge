#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<int> res, coins(n), path(n, -1);
        coins[n - 1] = A[0], path[n - 1] = n;
        for (auto i = n - 2; i >= 0; i--) {
            for (auto j = i + 1; j < min(n, i + B + 1); j++) {
                if (A[j] != -1 && (path[i] == -1 || coins[j] < coins[path[i]]))
                    path[i] = j, coins[i] = coins[j] + A[i];
            }
            if (path[i] == -1)
                A[i] = -1;
        }
        for (auto pos = 0; pos < n && path[pos] != -1; pos = path[pos])
            res.push_back(pos + 1);
        return res;
    }
};

int main(void) {
    return 0;
}
