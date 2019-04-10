#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    const string DEPARTURE = "JFK";
    const string MARK = "###";
    unordered_map<string, vector<string>> hash_map;

    bool dfs(vector<string>& path, int len) {
        if (len == 0)
            return true;
        auto& arrivals = hash_map[*path.rbegin()];
        for (auto arrival = arrivals.begin(); arrival != arrivals.end(); ++arrival) {
            if (*arrival == MARK)
                continue;
            path.push_back(*arrival);
            *arrival = MARK;
            if (dfs(path, len - 1))
                return true;
            *arrival = *path.rbegin();
            path.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        for (const auto& p : tickets) {
            hash_map[p.first].push_back(p.second);
        }
        for (auto& ticket : hash_map)
            sort(ticket.second.begin(), ticket.second.end());
        res.push_back(DEPARTURE);
        dfs(res, tickets.size());
        return res;
    }
};

int main(void) {
    vector<pair<string, string>> tickets = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
    };
    Solution().findItinerary(tickets);
    return 0;
}
