#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    void gen(string s, int left, int right, vector<string>& res) {
        if (left == 0) {
            if (right == 0) {
                res.push_back(s);
            }
            else {
                gen(s + ")", left, right - 1, res);
            }
            return;
        }
        gen(s + "(", left - 1, right, res);
        if (left < right)
            gen(s + ")", left, right - 1, res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = vector<string>();
        string s = "";
        gen(s, n, n, res);
        return res;
    }
};

int main(void) {
    cout << Solution().generateParenthesis(3).size() << endl;

    system("pause");
    return 0;
}
