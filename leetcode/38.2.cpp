#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    const int max_size = 4500;
public:
    string countAndSay(int n) {
        vector<char> res(max_size, '\0'), tmp(max_size, '\0');
        res[0] = '1';
        while (--n) {
            auto ind = 0;
            for (auto i = 0; res[i]; ) {
                auto j = i;
                while (res[++j] == res[i]);
                tmp[ind++] = j - i + '0';
                tmp[ind++] = res[i];
                i = j;
            }
            tmp[ind] = '\0';
            res.swap(tmp);
        }
        string seq = "";
        seq.reserve(max_size);
        for (auto i = 0; i < max_size && res[i]; i++) {
            seq += res[i];
        }
        return seq;
    }
};

int main(void) {
    cout << Solution().countAndSay(4) << endl;
    return 0;
}
