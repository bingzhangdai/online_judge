#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> hash_map;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(nullptr));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        hash_map[val].insert(nums.size());
        nums.push_back(val);
        return hash_map[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!hash_map.count(val) || hash_map[val].empty())
            return false;
        auto pos = *hash_map[val].cbegin();
        auto to_erase = nums[pos];
        auto last = nums[pos] = nums.back();
        nums.pop_back();
        hash_map[last].erase(nums.size());
        if (to_erase != last)
            nums[pos] = last,
            hash_map[val].erase(pos),
            hash_map[last].insert(pos);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main(void) {
    return 0;
}
