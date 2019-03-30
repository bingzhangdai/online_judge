#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
1, 11, 21, 1211, 111221, ...
*/
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return "";
        string seq = "1", tmp;
        while (--n) {
            tmp = "";
            for (int i = 0; i < seq.length();) {
                int j = i;
                while (seq[++j] == seq[i]);
                tmp.push_back(j - i + '0');
                tmp.push_back(seq[i]);
                i = j;
            }
            seq = tmp;
        }
        return seq;
    }
};

int main(void) {
    cout << Solution().countAndSay(4) << endl;
    system("pause");
    return 0;
}
