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
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (int i = 0; i < equations.size(); i++) {
            const auto& e = equations[i];
            auto v = values[i];
            hash_map[e.first].emplace_back(e.second, v);
            hash_map[e.second].emplace_back(e.first, 1.0 / v);
            visited[e.first] = false;
            visited[e.second] = false;
        }

        vector<double> result;
        double res;
        for (const auto& query : queries) {
            if (hash_map.find(query.first) == hash_map.end() || hash_map.find(query.second) == hash_map.end()) {
                result.push_back(-1);
                continue;
            }
            visited[query.first] = true;
            if (dfs(res, 1, query.first, query.second))
                result.push_back(res);
            else
                result.push_back(-1);
            visited[query.first] = false;
        }
        return result;
    }
};

int main(void) {
    return 0;
}
