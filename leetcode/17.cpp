#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    string a[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void dfs(string &digits, int i, vector<string> &res, string current) {
        if (i == digits.length()) {
            if (current != "")
                res.push_back(current);
            return;
        }
        string str = a[digits[i] - '0'];
        for (int j = 0; j < str.length(); j++) {
            dfs(digits, i + 1, res, current + str[j]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        dfs(digits, 0, res, "");
        return res;
    }
};

int main(void) {
    cout << Solution().letterCombinations("23")[0] << endl;

    system("pause");
    return 0;
}
