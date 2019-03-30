#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int res = num % 9;
        if (res)
            return res;
        else if (num)
            return 9;
        return 0;
    }
};

int main(void) {
    return 0;
}
