#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> hash_map;
    unordered_map<string, bool> visited;
    bool dfs(double& res, double val, const string& curr, const string& target) {
        if (curr == target) {
            res = val;
            return true;
        }

        for (const auto& next : hash_map[curr]) {
            if (!visited[next.first]) {
                visited[next.first] = true;
                bool find = dfs(res, val * next.second, next.first, target);
                visited[next.first] = false;
                if (find)
                    return true;
            }
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            const auto& e = equations[i];
            auto v = values[i];
            hash_map[e[0]].emplace_back(e[1], v);
            hash_map[e[1]].emplace_back(e[0], 1.0 / v);
            visited[e[0]] = false;
            visited[e[1]] = false;
        }

        vector<double> result;
        double res;
        for (const auto& query : queries) {
            if (!hash_map.count(query[0]) || !hash_map.count(query[1])) {
                result.push_back(-1);
                continue;
            }
            if (dfs(res, 1, query[0], query[1]))
                result.push_back(res);
            else
                result.push_back(-1);
        }
        return result;
    }
};

int main(void) {
    return 0;
}
