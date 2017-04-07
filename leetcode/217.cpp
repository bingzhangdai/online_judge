#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (const auto n : nums) {
            if (hash_set.find(n) != hash_set.end())
                return true;
            hash_set.insert(n);
        }
        return false;
    }
};

int main(void) {
    return 0;
}
