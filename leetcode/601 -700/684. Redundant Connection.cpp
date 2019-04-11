#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    int find_parent(const vector<int>& union_set, int n) {
        while (union_set[n] != 0)
            n = union_set[n];
        return n;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> union_set(edges.size() + 1, 0);
        for (const auto edge : edges) {
            auto x = edge[0], y = edge[1];
            int parent_x = find_parent(union_set, x), parent_y = find_parent(union_set, y);
            if (parent_x == parent_y)
                return edge;
            union_set[parent_x] = parent_y;
        }
        return {};
    }
};

int main(void) {
    return 0;
}
