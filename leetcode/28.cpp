#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        if (index == string::npos)
            return -1;
        return index;
    }
};

int main(void) {
    cout << Solution().strStr("mystr", "str") << endl;
    system("pause");
    return 0;
}
