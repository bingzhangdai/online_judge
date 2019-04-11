#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool isLower(char c) {
        return c >= 'a' && c <= 'z';
    }
public:
    bool detectCapitalUse(string word) {
        if (isUpper(word[0])) {
            if (word.length() > 1) {
                bool allUpper;
                if (isUpper(word[1]))
                    allUpper = true;
                else if (isLower(word[1]))
                    allUpper = false;
                else
                    return false;
                for (int i = 2; i < word.length(); i++) {
                    if (isUpper(word[i]) && !allUpper || isLower(word[i]) && allUpper)
                        return false;
                }
            }
            return true;
        }
        for (int i = 1; i < word.length(); i++) {
            if (isUpper(word[i]))
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
