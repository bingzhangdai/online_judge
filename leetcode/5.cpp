#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), max(1), begin(0);
        bool flag[1000][1000];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= i; j++)
                flag[i][j] = true;
            for (int j = i + 1; j < len; j++)
                flag[i][j] = false;
        }
        for (int j = 0; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] != s[j])
                    flag[i][j] = false;
                else {
                    flag[i][j] = flag[i + 1][j - 1];
                    if (flag[i][j] && j - i + 1 > max) {
                        begin = i;
                        max = j - i + 1;
                    }
                }
            }
        }
        return s.substr(begin, max);
    }
};

int main(void) {
    Solution s = Solution();
    
    string str;
    cin >> str;
    cout << s.longestPalindrome(str) << endl;

    system("pause");
    return 0;
}
