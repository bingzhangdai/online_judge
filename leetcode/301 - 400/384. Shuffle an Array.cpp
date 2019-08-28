#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums): nums(nums) {
        srand(time(nullptr));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    int randInt(int n, int m) {
        return std::rand() % (m - n) + n;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto res = nums;
        for (auto i = 0; i < res.size(); i++) {
            swap(res[i], res[randInt(i, res.size())]);
        }
        return res;
    }
};

class Solution_OLD {
    vector<int> nums;
public:
    Solution(vector<int>& nums) : nums(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        auto tmp = reset();
        std::shuffle(tmp.begin(), tmp.end(), g);
        return tmp;
    }
};

int main(void) {
    return 0;
}
