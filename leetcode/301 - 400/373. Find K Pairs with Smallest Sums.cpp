#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> heap;
        if (nums1.size() && nums2.size())
            heap.push(make_tuple(nums1[0] + nums2[0], 0, 0));
        vector<pair<int, int>> res;
        while (k-- && !heap.empty()) {
            auto top = heap.top();
            while (!heap.empty() && heap.top() == top)
                heap.pop();
            int i = get<1>(top), j = get<2>(top);
            res.emplace_back(nums1[i], nums2[j]);
            ++i;
            ++j;
            if (i < nums1.size())
                heap.push(make_tuple(nums1[i] + nums2[j - 1], i, j - 1));
            if (j < nums2.size())
                heap.push(make_tuple(nums1[i - 1] + nums2[j], i - 1, j));
        }
        return res;
    }
};

int main(void) {
    return 0;
}
