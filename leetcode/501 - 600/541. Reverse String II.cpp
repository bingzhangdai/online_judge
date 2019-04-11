#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
    void reverse(string& s, int i, int j) {
        while (i < j)
            swap(s[i++], s[j--]);
    }
public:
    string reverseStr(string s, int k) {
        int start = 0, end = k - 1;
        while (start < s.length()) {
            reverse(s, start, min(end, (int)s.length() - 1));
            start += k * 2;
            end += k * 2;
        }
        return s;
    }
};

int main(void) {
    return 0;
}
