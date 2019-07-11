#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        auto N = quality.size();
        vector<pair<double, int>> ratio;
        for (auto i = 0; i < N; i++)
            ratio.emplace_back(1.0 * wage[i] / quality[i], quality[i]);
        sort(ratio.begin(), ratio.end());
        priority_queue<int> heap;
        auto q = 0;
        for (auto i = 0; i < K; i++) {
            q += ratio[i].second;
            heap.push(ratio[i].second);
        }
        auto res = ratio[K - 1].first * q;
        for (auto i = K; i < N; i++) {
            q += ratio[i].second;
            heap.push(ratio[i].second);
            q -= heap.top();
            heap.pop();
            res = min(res, q * ratio[i].first);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
