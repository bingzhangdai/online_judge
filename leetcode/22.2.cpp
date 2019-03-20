#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    void dfs(string s, int left_rem, int right_rem, vector<string> &res) {
        if (left_rem == 0 && right_rem == 0) {
            res.push_back(s);
            return;
        }
        if (left_rem) {
            dfs(s + '(', left_rem - 1, right_rem + 1, res);
        }
        if (right_rem) {
            dfs(s + ')', left_rem, right_rem - 1, res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", n, 0, res);
        return res;
    }
};

int main(void) {
    cout << Solution().generateParenthesis(3).size() << endl;

    system("pause");
    return 0;
}
