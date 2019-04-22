#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Examples: 
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        string res;
        while (i < s.length()) {
            int pos = i;
            while (pos < s.length()) {
                if (s[pos] >= '0' && s[pos] <= '9') {
                    break;
                }
                pos++;
            }
            res += s.substr(i, pos - i);
            if (pos == s.length())
                return res;
            int num_end = 0;
            for (int j = pos; j < s.length(); j++) {
                if (s[j] == '[') {
                    num_end = j;
                    break;
                }
            }
            int num = stoi(s.substr(pos, num_end - pos));
            int substr_end = 0, count = 0, recursive = false;
            for (int j = num_end + 1; j < s.length(); j++) {
                if (s[j] == '[') {
                    recursive = true;
                    count++;
                }
                if (s[j] == ']') {
                    if (count == 0) {
                        substr_end = j;
                        break;
                    }
                    count--;
                }
            }
            string substr = recursive ? decodeString(s.substr(num_end + 1, substr_end - num_end - 1))
                : s.substr(num_end + 1, substr_end - num_end - 1);
            while (num--)
                res += substr;
            i = substr_end + 1;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
