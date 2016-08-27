#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (auto i = 1; i < n; i++) {
            for (auto j = 0; j <= i; j++) {
                auto cursum = INT_MAX;
                if (j != 0)
                    cursum = min(triangle[i-1][j-1] + triangle[i][j], cursum);
                if (j != i)
                    cursum = min(triangle[i-1][j] + triangle[i][j], cursum);
                triangle[i][j] = cursum;
            }
        }
        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};

int main(void) {
    return 0;
}
