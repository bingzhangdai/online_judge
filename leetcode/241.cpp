#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> diffWaysToCompute(const string& input, int right, int left) {
        vector<int> res;
        for (int i = right; i < left; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                auto left_res = diffWaysToCompute(input, right, i);
                auto right_res = diffWaysToCompute(input, i + 1, left);
                for (const auto l : left_res)
                    for (const auto r : right_res)
                        switch (input[i]) {
                            case '+':
                                res.push_back(l + r);
                                break;
                            case '-':
                                res.push_back(l - r);
                                break;
                            case '*':
                                res.push_back(l * r);
                                break;
                        }
            }
        }
        if (res.size() == 0)
            res.push_back(stoi(input.substr(right, left - right)));
        return res;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        return diffWaysToCompute(input, 0, input.size());
    }
};

int main(void) {
    return 0;
}
