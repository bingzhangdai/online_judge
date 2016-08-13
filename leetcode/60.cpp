#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    int factorial(int n) {
        if (n == 0)
            return 1;
        int res = 1;
        while (n)
            res *= n--;
        return res;
    }
public:
    string getPermutation(int n, int k) {
        auto num = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
            num[i] = i + 1;
        string res = "";
        k--;
        while (n) {
            int fac = factorial(--n);
            int pos = k / fac;
            res += num[pos] + '0';
            num.erase(num.begin() + pos);
            k %= fac;
        }
        return res;
    }
};

int main(void) {
    // 312
    cout << Solution().getPermutation(3, 2) << endl;
    // system("pause");
    return 0;
}
