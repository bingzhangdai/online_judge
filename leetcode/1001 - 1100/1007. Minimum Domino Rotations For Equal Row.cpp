#include <iostream>
#include <vector>
using namespace std;

/*
One observation is that, if A[0] works, no need to check B[0].
Because if both A[0] and B[0] exist in all dominoes,
the result will be the same.
*/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size(), res = -1;
        for (auto val : {A[0], B[0]}) {
            auto count = 0, same_count = 0;
            for (auto i = 0; i < n; i++) {
                if (A[i] == B[i])
                    same_count++;
                if (A[i] == val)
                    continue;
                if (B[i] == val)
                    count++;
                else {
                    count = -1;
                    break;
                }
            }
            if (count == -1)
                continue;
            return min(count, n - same_count - count);
        }
        return -1;
    }
};

int main(void) {
    return 0;
}
