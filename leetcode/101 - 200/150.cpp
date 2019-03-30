#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    bool isNum(string s) {
        if (s[0] == '-' || s[0] == '+')
            s = s.substr(1, s.length() - 1);
        if (s == "")
            return false;
        for (auto c : s)
            if (c < '0' || c > '9')
                return false;
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (isNum(tokens[i]))
                stk.push(stoi(tokens[i]));
            else {
                auto right = stk.top();
                stk.pop();
                auto left = stk.top();
                stk.pop();
                if (tokens[i] == "+")
                    stk.push(left + right);
                if (tokens[i] == "-")
                    stk.push(left - right);
                if (tokens[i] == "*")
                    stk.push(left * right);
                if (tokens[i] == "/")
                    stk.push(left / right);
            }
        }
        return stk.top();
    }
};

int main(void) {
    return 0;
}
