#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash_map;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return nullptr;
        if (hash_map.find(node) == hash_map.end()) {
            hash_map[node] = new UndirectedGraphNode(node->label);
            for (auto neighbor : node->neighbors)
                hash_map[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return hash_map[node];
    }
};

int main(void) {
    return 0;
}