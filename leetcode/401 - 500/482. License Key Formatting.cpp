#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    char to_upper(char c) {
        if (c >= 'a' && c <= 'z')
            return c - 'a' + 'A';
        return c;
    }
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        for (int i = S.length() - 1; i >= 0;) {
            int count = 0;
            int curr = i;
            while (count < K && curr >= 0) {
                if (S[curr] != '-') {
                    count++;
                    res += to_upper(S[curr]);
                }
                curr--;
            }
            res += '-';
            i = curr;
        }
        while (res.back() == '-') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(void) {
    return 0;
}
