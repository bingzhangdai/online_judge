#include <iostream>
#include <vector>
#include <math>
#include <unordered_set>
using namespace std;

class Solution {
    bool dfs(string curr, unordered_set<string>& visited, vector<string>& path, int k, int max_len) {
        auto prefix = curr.substr(1);
        for (int i = 0; i < k; i++) {
            auto next = prefix + static_cast<char>('0' + i);
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                path.push_back(string(1, '0' + i));
                if (path.size() == max_len) {
                    return true;
                }
                if (dfs(next, visited, path, k, max_len))
                    return true;
                visited.erase(visited.find(next));
                path.pop_back();
            }
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        int num_nodes = pow(k, n);
        auto curr = string(n, '0');
        unordered_set<string> visited{ curr };
        vector<string> path{ curr };
        dfs(curr, visited, path, k, num_nodes);
        string res = "";
        for (const auto& p : path)
            res.append(p);
        return res;
    }
};

int main(void) {
    return 0;
}
