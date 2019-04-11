#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
'A' : Absent. 
'L' : Late.
'P' : Present. 
*/

class Solution {
    const int mod = 1E9 + 7;
public:
    int checkRecord(int n) {
        long A0L0(1), A0L1(0), A0L2(0), A1L0(0), A1L1(0), A1L2(0);
        while (n--) {
            long A0L0_curr(0), A0L1_curr(0), A0L2_curr(0), A1L0_curr(0), A1L1_curr(0), A1L2_curr(0);
            // A
            A1L0_curr += A0L0 + A0L1 + A0L2;
            // L
            A0L1_curr += A0L0;
            A0L2_curr += A0L1;
            A1L1_curr += A1L0;
            A1L2_curr += A1L1;
            // P
            A0L0_curr += A0L0 + A0L1 + A0L2;
            A1L0_curr += A1L0 + A1L1 + A1L2;
            // Update
            A0L0 = A0L0_curr % mod;
            A0L1 = A0L1_curr % mod;
            A0L2 = A0L2_curr % mod;
            A1L0 = A1L0_curr % mod;
            A1L1 = A1L1_curr % mod;
            A1L2 = A1L2_curr % mod;
        }
        return (A0L0 + A0L1 + A0L2 + A1L0 + A1L1 + A1L2) % mod;
    }
};

int main(void) {
    return 0;
}
