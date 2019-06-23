#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    int dist(const string& s, const string& t) {
        int res = min(s.length(), t.length());
        while (res) {
            if (s.substr(s.length() - res) == t.substr(0, res))
                return res;
            res--;
        }
        return res;
    }
    void build_graph(vector<string>& A, vector<vector<int>>& graph) {
        for (auto i = 0; i < A.size(); i++) {
            for (auto j = 0; j < i; j++) {
                graph[i][j] = dist(A[i], A[j]);
                graph[j][i] = dist(A[j], A[i]); 
            }
        }
    }
public:
    string shortestSuperstring(vector<string>& A) {
        auto n = A.size();
        vector<vector<int>> graph(n, vector<int>(n));
        build_graph(A, graph);
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX)),
                            path(1 << n, vector<int>(n, INT_MAX));
        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (((1 << j) & i) == 0)
                    continue;
                auto prev = i - (1 << j);
                if (prev == 0) {
                    dp[i][j] = A[i].length();
                }
                else {
                    for (int k = 0; k < n; k++) {
                        if (dp[prev][k] != INT_MAX && (dp[prev][k] + graph[k][j] < dp[i][j])) {
                            dp[i][j] = dp[prev][k] + graph[k][j];
                            path[i][j] = k;
                        }
                    }
                }
            }
        }
        auto status = (1 << n) - 1;
        auto last = min_element(dp[status].begin(), dp[status].end()) - dp[status].begin();
        string res = A[last];
        while (status) {
            auto prev = path[status][last];
            res.insert(0, A[prev].substr(0, A[prev].length() - A[last].length() + graph[prev][last]));
            status -= (1 << last);
            last = prev;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
