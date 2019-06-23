#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    void to_actual_string(string& s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                int j = i - 1;
                while (j >= 0 && s[j] == '#')
                    j--;
                if (j >= 0)
                    s[j] = '#';
            }
        }
    }
    int to_next_index(const string& s, int i) {
        while (i < s.length())
            if (s[i] == '#')
                i++;
            else
                break;
        return i;
    }
public:
    bool backspaceCompare(string S, string T) {
        to_actual_string(S);
        to_actual_string(T);
        int i = 0, j = 0;
        while (true) {
            i = to_next_index(S, i);
            j = to_next_index(T, j);
            if (i >= S.length() && j >= T.length())
                return true;
            if (i >= S.length() || j >= T.length())
                return false;
            if (S[i] != T[j])
                return false;
            i++, j++;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
