#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size());
        dp[0] = books[0][1];
        for (int i = 1; i < books.size(); i++) {
            int j = i, w = 0, h = 0, res = INT_MAX;
            while (j >= 0) {
                w += books[j][0];
                h = max(h, books[j][1]);
                if (w > shelf_width)
                    break;
                res = min(res, h + (j - 1 >= 0 ? dp[j - 1] : 0));
                j--;
            }
            dp[i] = res;
        }
        return dp.back();
    }
};

int main(void) {
    return 0;
}
