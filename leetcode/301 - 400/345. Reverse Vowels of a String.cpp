#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    set<char> vowels{ 'a', 'e', 'i', 'o', 'u' ,'A', 'E', 'I', 'O', 'U' };
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && vowels.find(s[i]) == vowels.end())
                i++;
            while (i < j && vowels.find(s[j]) == vowels.end())
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main(void) {
    return 0;
}
