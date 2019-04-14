#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string magic = "12211";
        int pos = 3;
        while (magic.length() < n) {
            char next = magic.back() == '1' ? '2' : '1';
            magic += next;
            if (magic[pos++] == '2')
                magic += next;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (magic[i] == '1')
                res++;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
