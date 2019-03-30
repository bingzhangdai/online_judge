#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> pair = {
            { ')', '(' },
            { ']', '[' },
            { '}', '{' }
        };
        for (auto c : s) {
            if (pair.find(c) == pair.end()) {
                stk.push(c);
            }
            else {
                if (!stk.empty() && stk.top() == pair[c]) {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

int main(void) {
    cout << Solution().isValid("(){}[]") << endl;

    system("pause");
    return 0;
}
