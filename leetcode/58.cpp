#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s == "")
            return 0;
        int i = s.length();
        while (i && s[--i] == ' ');
        int j = i;
        while (j >= 0 && s[j] != ' ') j--;
        return i - j;
    }
};

int main(void) {
    cout << Solution().lengthOfLastWord("hello World") << endl;
    // system("pause");
    return 0;
}
