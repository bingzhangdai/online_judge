#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for_each(nums.begin(), nums.end(), [&hash_set](int i) { hash_set.insert(i); });
        int max_count = 0;
        while (hash_set.size()) {
            auto p = hash_set.begin();
            auto num = *p;
            hash_set.erase(p);
            int i = 1, j = 1;
            while ((p = hash_set.find(num + i)) != hash_set.end()) {
                hash_set.erase(p);
                i++;
            }
            while ((p = hash_set.find(num - j)) != hash_set.end()) {
                hash_set.erase(p);
                j++;
            }
            if (max_count < i + j - 1)
                max_count = i + j - 1;
        }
        return max_count;
    }
};

int main(void) {
    return 0;
}
