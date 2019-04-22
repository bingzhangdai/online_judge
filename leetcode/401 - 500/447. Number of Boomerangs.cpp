#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    int dist(const pair<int, int>& i, const pair<int, int>& j) {
        int x = i.first - j.first, y = i.second - j.second;
        return x * x + y * y;
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.empty())
            return 0;
        int n = points.size();
        vector<vector<int>> dists(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                dists[i][j] = dists[j][i] = dist(points[i], points[j]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (i == k)
                        continue;
                    if (dists[i][j] == dists[i][k])
                        res += 2;
                }
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
