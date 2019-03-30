#include <iostream>
#include <unordered_map>
#include <priority_queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for (auto num : nums)
            hash_map[num]++;
        vector<int> res;
        priority_queue<pair<int, int>> heap;
        for (auto it : hash_map)
            heap.emplace(pair<int, int>(it.second, it.first));
        while (k--) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};

int main(void) {
    return 0;
}
