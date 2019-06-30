#include <iostream>
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    bool dfs(int n, const vector<unordered_set<int>>& edges_map, int source, int destination, vector<bool>& visited) {
        if (source == destination)
            return true;
        if (edges_map[source].empty())
            return false;
        for (auto next : edges_map[source]) {
            if (visited[next])
                return false;
            visited[next] = true;
            if (!dfs(n, edges_map, next, destination, visited))
                return false;
            visited[next] = false;
        }
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<unordered_set<int>> edges_map(n, unordered_set<int>());
        for (const auto& edge : edges) {
            edges_map[edge[0]].insert(edge[1]);
            // if (edges_map[edge[1]].find(edge[0]) != edges_map[edge[1]].end())
            //     return false;
        }
        if (edges_map[destination].size() != 0)
            return false;
        vector<bool> visited(n, false);
        return dfs(n, edges_map, source, destination, visited);
    }
};

int main(void) {
    return 0;
}
