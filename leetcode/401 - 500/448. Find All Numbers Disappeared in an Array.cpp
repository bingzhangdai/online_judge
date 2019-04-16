#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i - 1] == i || nums[nums[i - 1] - 1] == nums[i - 1])
                continue;
            int curr = i, next = nums[i - 1];
            while (next != nums[next - 1]) {
                int tmp = nums[next - 1];
                nums[next - 1] = next;
                curr = next;
                next = tmp;
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                res.push_back(i + 1);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
