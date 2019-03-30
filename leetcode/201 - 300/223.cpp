#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        auto I = static_cast<long long>(min(C, G)) - max(A, E), J = static_cast<long long>(min(D, H)) - max(B, F);
        return (C - A) * (D - B) + (G - E) * (H - F) - ((I > 0 && J > 0) ? I * J : 0);
    }
};

int main(void) {
    cout << Solution().computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;
    return 0;
}
