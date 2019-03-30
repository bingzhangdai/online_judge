#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example 1:
Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
Example 2:
Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:
Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.
*/

class Solution {
    vector<int> char_map;
public:
    Solution() {
        int num = 'z' - 'a' + 1;
        char_map.resize(num);
        for (int i = 0; i < num; i++)
            char_map[i] = (1 << i);
    }
    int maxProduct(vector<string>& words) {
        int len = words.size();
        if (len == 0)
            return 0;
        vector<int> words_map(len, 0);
        for (int i = 0; i < len; i++) {
            for (auto c : words[i])
                words_map[i] |= char_map[c - 'a'];
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((words_map[i] & words_map[j]) == 0)
                    res = max(res, (int)(words[i].length() * words[j].length()));
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
