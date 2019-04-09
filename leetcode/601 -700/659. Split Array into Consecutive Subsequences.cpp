#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<pair<int, int>>, vector<int>, greater<int>> heap;
        int count = 0;
        for (auto n : nums) {
            while (!heap.empty() && heap.top().first < n - 1) {
                if (heap.top().second < 3)
                    return false;
                count += heap.top().second / 3;
                heap.pop();
            }
            if (heap.empty() || heap.top().first != n - 1) {
                heap.push(pair<int, int>(n, 1));
            }
            else {
                auto p = heap.top();
                heap.pop();
                p.first++;
                p.second++;
                heap.push(p);
            }
        }
        while (!heap.empty()) {
            auto p = heap.top();
            if (p.second < 3)
                return false;
            count += p.second / 3;
            heap.pop();
        }
        return count >= 1;
    }
};

// LTE
/*
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        deque<pair<int, int>> count;
        for (auto n : nums) {
            auto found = count.end();
            for (auto it = count.begin(); it != count.end(); ++it) {
                if (it->first == n - 1) {
                    if (found == count.end() || found->second > it->second)
                        found = it;
                }
            }
            if (found != count.end()) {
                found->first++;
                found->second++;
            }
            else {
                count.emplace_back(n, 1);
            }
        }
        if (count.empty())
            return false;
        for (const auto& c : count)
            if (c.second < 3)
                return false;
        return true;
    }
};
*/

int main(void) {
    return 0;
}
