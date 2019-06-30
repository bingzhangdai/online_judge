#include <iostream>
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    int Manhattan(const vector<int>& worker, const vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<tuple<int, int, int>> dist_pair;
        for (auto i = 0; i < workers.size(); i++) {
            for (auto j = 0; j < bikes.size(); j++) {
                dist_pair.emplace_back(Manhattan(workers[i], bikes[j]), i, j);
            }
        }
        sort(dist_pair.begin(), dist_pair.end());
        vector<int> res(workers.size(), -1);
        unordered_set<int> worker_indices, bike_indices;
        for (const auto& dist : dist_pair) {
            if (worker_indices.find(get<1>(dist)) != worker_indices.end() ||
                bike_indices.find(get<2>(dist)) != bike_indices.end())
                continue;
            res[get<1>(dist)] = get<2>(dist);
            worker_indices.insert(get<1>(dist));
            bike_indices.insert(get<2>(dist));
        }
        return res;
    }
};

int main(void) {
    return 0;
}
