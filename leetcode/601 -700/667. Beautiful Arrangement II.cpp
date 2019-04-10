#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        for (int i = 1, j = n, ind = 0; ind < n; ind++) {
            if (ind < k)
                res[ind] = ind & 1 ? j-- : i++;
            else
                res[ind] = k & 1 ? i++: j--;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
