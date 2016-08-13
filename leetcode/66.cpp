#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto res = vector<int>();
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int t = digits[i] + carry;
            res.insert(res.begin(), t % 10);
            carry = t / 10;
        }
        if (carry)
            res.insert(res.begin(), carry);
        return res;
    }
};

int main(void) {
    vector<int> digits = {1, 9, 9};
    cout << Solution().plusOne(digits)[0] << endl;
    // system("pause");
    return 0;
}
