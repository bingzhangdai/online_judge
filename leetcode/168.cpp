#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            res = static_cast<char>((n-1) % 26 + 'A') + res;
            n = (n-1) / 26;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
