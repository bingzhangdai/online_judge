#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s == "")
            return 0;
        int a, b, c = (s[0] == '0') ? 0 : 1;
        b = c;
        for (int i = 1; i < s.size(); i++) {
            a = b;
            b = c;
            if (s[i] == '0') {
                if (s[i-1] >= '1' && s[i-1] <= '2')
                    c = a;
                else
                    return 0;
            }
            else if (s[i] >= '1' && s[i] <= '6') {
                if (s[i-1] >= '1' && s[i-1] <= '2')
                    c = a + b;
                else
                    c = b;
            }
            else {
                if (s[i-1] == '1')
                    c = a + b;
                else
                    c = b;
            }
        }
        return c;
    }
};

int main(void) {
    cout << Solution().numDecodings("12") << endl;
    // system("pause");
    return 0;
}
