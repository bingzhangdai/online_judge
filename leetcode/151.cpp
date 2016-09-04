#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    void trim(string& s) {
        if (s == "")
            return;
        int i = 0; 
        for (i = 0; i < s.size(); i++)
            if (s[i] != ' ')
                break;
        s.erase(0, i);
        if (s == "")
            return;
        for (i = s.size() - 1; i >= 0; i--)
            if (s[i] != ' ')
                break;
        s.erase(i + 1, s.size() - i - 1);
    }
    void reverse(string& s, int left, int right) {
        while (left++ < right--)
            swap(s[left-1], s[right+1]);
    }
public:
    void reverseWords(string &s) {
        trim(s);
        reverse(s, 0, s.size() - 1);
        int i, j, k;
        for (i = 0; i < s.size();) {
            for (j = i; j < s.size(); j++)
                if (s[j] == ' ')
                    break;
            reverse(s, i, j - 1);
            for (k = j + 1; k < s.size(); k++)
                if (s[k] != ' ')
                    break;
            if (k - j > 1)
                s.erase(j, k - j - 1);
            i = j + 1;
        }
    }
};

int main(void) {
    string s = "   123   ";
    Solution().reverseWords(s);
    return 0;
}
/*
Given an input string, reverse the string word by word. 
For example,
Given s = "the sky is blue",
return "blue is sky the". 
*/
