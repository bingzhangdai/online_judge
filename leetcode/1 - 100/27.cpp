#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val)
                nums[m++] = nums[i];
        }
        return m;
    }
};

int main(void) {
    cout << Solution().removeElement(vector<int>({3, 2, 2, 3}), 3) << endl;

    system("pause");
    return 0;
}
