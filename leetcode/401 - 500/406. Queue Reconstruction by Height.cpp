#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
        vector<pair<int, int>> res(n, pair<int, int>(INT_MAX, 0));
        sort(people.begin(), people.end());
        for (int i = 0; i < n; i++) {
            const auto& p = people[i];
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (res[j].first >=  p.first) {
                    if (count == p.second) {
                        res[j] = p;
                        break;
                    }
                    count++;
                }
            }
        }
        return res;
    }
};

int main(void) {
    return 0;
}
