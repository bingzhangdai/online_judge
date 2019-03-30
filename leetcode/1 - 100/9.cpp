#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int len = 1;
        while ((x / len) >= 10)
            len *= 10;
        while (x) {
            if (x / len != x % 10)
                return false;
            x = (x % len) / 10;
            len /= 100;
        }
        return true;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.isPalindrome(1001) << endl;

    system("pause");
    return 0;
}
