#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res { 0, 1 };
        if (n == 0)
            return vector<int>(1, 0);
        for (int i = 1; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back((1 << i) + res[j]);
            }
        }
        return res;
    }
};

int main(void) {
    cout << Solution().grayCode(2).size() << endl;
    // system("pause");
    return 0;
}
