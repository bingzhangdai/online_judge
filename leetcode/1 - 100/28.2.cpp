#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] != needle[0])
                continue;
            int j = 0;
            while (j < needle.length() && needle[j] == haystack[i + j]) {
                j++;
            }
            if (j == needle.length())
                return i;
        }
        return -1;
    }
};

int main(void) {
    cout << Solution().strStr("mystr", "str") << endl;
    system("pause");
    return 0;
}
