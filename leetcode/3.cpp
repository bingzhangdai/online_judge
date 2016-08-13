#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i(0), j(0), max(0);
        while(i++ < s.size()) {
            int k;
            for (k = j; k < i-1; k++)
                if (s[k] == s[i-1])
                    break;
            if (k < i - 1)
                j = k+1;
            if (max < i-j)
                max = i-j;
        }
        return max;
    }
};
