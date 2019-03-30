#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> res {1};
        while (numRows--) {
            res.push_back(1);
            for (int i = res.size() - 2; i > 0; i--)
                res[i] = res[i] + res[i-1];
        }
        return res;
    }
};
int main(void) {
    return 0;
}
