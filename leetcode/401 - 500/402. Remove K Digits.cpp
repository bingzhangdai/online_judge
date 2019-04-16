#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        while (k--) {
            bool erased = false;
            for (int i = 0; i + 1 < num.size(); i++) {
                if (num[i] > num[i + 1]) {
                    num.erase(num.begin() + i);
                    while (!num.empty() && num.front() == '0')
                        num.erase(num.begin());
                    erased = true;
                    break;
                }
            }
            if (num.length() && !erased)
                num.pop_back();
            if (num.length() == 0)
                return "0";
        }
        return num;
    }
};

int main(void) {
    return 0;
}
