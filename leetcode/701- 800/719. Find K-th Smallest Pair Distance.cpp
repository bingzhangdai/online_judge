#include <iostream>
#include <priority_queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
    int countSmallerorEqual(const vector<int>& nums, int target) {
        int i = 0, j = upper_bound(nums.begin(), nums.end(), nums.front() + target) - nums.begin() - 1;
        int count = (j - i + 1) * (j - i) / 2;
        while (j < nums.size() - 1) {
            auto next = upper_bound(nums.begin() + j, nums.end(), nums[i + 1] + target) - nums.begin() - 1;
            count += (next - j) * (j - i) + (next - j) * (next - j - 1) / 2;
            j = next;
            i++;
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int> & nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = (left + right) / 2;
            int count = countSmallerorEqual(nums, mid);
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

class Solution_Heap_LTE {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> heap;
        for (int i = 1; i < nums.size(); i++) {
            heap.emplace(nums[i] - nums[i - 1], i, i - 1);
        }
        while (--k) {
            const auto top = heap.top();
            heap.pop();
            auto i = get<1>(top), j = get<2>(top);
            if (j > 0)
                heap.emplace(nums[i] - nums[j - 1], i, j - 1);
        }
        return get<0>(heap.top());
    }
};

int main(void) {
    return 0;
}
