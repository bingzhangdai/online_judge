#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> hash_map;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash_map.count(val))
            return false;
        hash_map[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!hash_map.count(val))
            return false;
        auto pos = hash_map[val];
        hash_map[nums[pos] = nums.back()] = pos;
        nums.pop_back();
        hash_map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main(void) {
    return 0;
}
