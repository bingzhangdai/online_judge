#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        auto is_palindrome = true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            auto pre = s[i], post = s[j];
            if (pre >= 'A' && pre <= 'Z')
                pre += 'a' - 'A';
            if (post >= 'A' && post <= 'Z')
                post += 'a' - 'A';
            if (!(pre >= 'a' && pre <= 'z' || pre>= '0' && pre <= '9')) {
                i++;
                continue;
            }
            if (!(post >= 'a' && post <= 'z' || post>= '0' && post <= '9')) {
                j--;
                continue;
            }
            if  (post != pre) {
                is_palindrome = false;
                break;
            }
            i++;
            j--;
        }
        return is_palindrome;
    }
};

int main(void) {
    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}
