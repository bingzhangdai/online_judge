#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int m = 0;
        if (nums.size() == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                nums[++m] = nums[i];
        }
        return m + 1;
    }
};

int main(void) {
    cout << Solution().removeDuplicates(vector<int>({1, 1, 2})) << endl;

    system("pause");
    return 0;
}
