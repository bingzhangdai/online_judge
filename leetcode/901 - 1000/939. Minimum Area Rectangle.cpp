#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

/*
1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
*/

class Solution {
    const int max_val = 40001;
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        unordered_map<int, int> last_seen;
        int res = INT_MAX;
        for (int i = 0; i < points.size();) {
            int j = i + 1, x = points[i][0];
            while (j < points.size() && points[j][0] == x)
                j++;
            for (int m = i + 1; m < j; m++) {
                for (int n = i; n < m; n++) {
                    int y_coor = points[n][1] * max_val + points[m][1];
                    if (last_seen.find(y_coor) != last_seen.end()) {
                        res = min((x - last_seen[y_coor]) * (points[m][1] - points[n][1]), res);
                    }
                    last_seen[y_coor] = x;
                }
            }
            i = j;
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main(void) {
    return 0;
}
