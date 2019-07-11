#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, vector<int>> group;
        for (int i = 0; i < values.size(); i++) {
            group[labels[i]].push_back(values[i]);
        }
        vector<int> candidates;
        for (auto& p : group) {
            sort(p.second.begin(), p.second.end(), greater<>());
            for (int i = 0; i < p.second.size() && i < use_limit; i++)
                candidates.push_back(p.second[i]);
        }
        sort(candidates.begin(), candidates.end(), greater<>());
        int res = 0;
        for (int i = 0; i < num_wanted && i < candidates.size(); i++)
            res += candidates[i];
        return res;
    }
};

int main(void) {
    return 0;
}
