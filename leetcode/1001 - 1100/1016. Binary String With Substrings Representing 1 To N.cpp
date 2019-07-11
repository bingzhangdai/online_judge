#include <iostream>
#include <string>
using namespace std;

class Solution {
    string to_bin_string(int n) {
        string res = "";
        int bit = (1 << 30);
        while ((n & bit) == 0)
            bit >>= 1;
        while (bit) {
            res.push_back((bit & n) ? '1' : '0');
            bit >>= 1;
        }
        return res;
    }
public:
    bool queryString(string S, int N) {
        int bit = (1 << 30);
        while ((N & bit) == 0)
            bit >>= 1;
        auto low = N - (N & bit);
        for (int i = N; i > low; i--) {
            // cout << to_bin_string(i) << endl;
            if (S.find(to_bin_string(i)) == -1)
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
