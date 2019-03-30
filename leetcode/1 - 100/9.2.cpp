#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        auto origin = x;
        if (x < 0)
            return false;
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res > INT_MAX
                ? false
                : ((int) res) == origin;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.isPalindrome(121) << endl;

    return 0;
}
