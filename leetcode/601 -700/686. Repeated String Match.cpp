#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lower = (B.length() + A.length() - 1) / A.length(), upper = (B.length() + A.length() - 3) / A.length() + 2;
        string s = "";
        for (int i = 0; i < lower; i++)
            s += A;
        for (int i = lower; i <= upper; i++) {
            if (s.find(B) != -1)
                return i;
            s += A;
        }
        return -1;
    }
};

int main(void) {
    return 0;
}
