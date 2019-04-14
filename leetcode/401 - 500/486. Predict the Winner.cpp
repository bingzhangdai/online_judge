#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool dfs(const vector<int>& nums, int begin, int end, int score1, int score2, int turn) {
        if (begin > end) {
            return score1 >= score2;
        }
        if (turn == 1) {
            return dfs(nums, begin + 1, end, score1 + nums[begin], score2, 2) ||
                dfs(nums, begin, end - 1, score1 + nums[end], score2, 2);
        } else {
            return dfs(nums, begin + 1, end, score1, score2 + nums[begin], 1) &&
                dfs(nums, begin, end - 1, score1, score2 + nums[end], 1);
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1, 0, 0, 1);
    }
};

int main(void) {
    return 0;
}
