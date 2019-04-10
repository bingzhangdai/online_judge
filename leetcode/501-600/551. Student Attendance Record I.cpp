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
public:
    bool checkRecord(string s) {
        int num_A = 0, num_L = 0;
        for (auto r : s) {
            if (r == 'A')
                num_A++;
            if (r == 'L')
                num_L++;
            else
                num_L = 0;
            if (num_A > 1 || num_L > 2)
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
