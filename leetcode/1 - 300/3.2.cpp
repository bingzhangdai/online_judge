#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", which the length is 3.
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto i = 0, j = 0, res = 0;
        while (i++ < s.length()) {
            auto k = j;
            while (k++ < i) {
                if (s[k-1] == s[i-1]) {
                    break;
                }
            }
            if (k != i) {
                j = k;
            }
            res = max(res, i - j);
        }
        return res;
    }
};

int main(void) {
    auto s = Solution();
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}
