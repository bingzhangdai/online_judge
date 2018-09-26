#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    vector<string> phone_num = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void dfs(const string &digits, int index, vector<string> &res, string path) {
        if (index == digits.length()) {
            if (path != "")
                res.push_back(path);
            return;
        }
        int digit = digits[index] - '0';
        for (auto c : phone_num[digit]) {
            dfs(digits, index + 1, res, path + c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        auto res = vector<string>();
        dfs(digits, 0, res, "");
        return res;
    }
};

int main(void) {
    cout << Solution().letterCombinations("23").size() << endl;
    return 0;
}
