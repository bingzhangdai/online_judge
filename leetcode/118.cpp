#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        res.push_back( {1} );
        while (--numRows) {
            vector<int> cur {1};
            auto j = res.size() - 1;
            for (int i = 0; i < res[j].size() - 1; i++)
                cur.push_back(res[j][i] + res[j][i+1]);
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;
    }
};
int main(void) {
    return 0;
}
