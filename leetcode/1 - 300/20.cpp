#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        vector<char> stack = vector<char>();
        for (auto i : s) {
            switch (i) {
            case '(': case '[': case '{':
                stack.push_back(i);
                break;
            case ')':
                if (stack.size() == 0 || stack.back() != '(')
                    return false;
                else
                    stack.pop_back();
                break;
            case '}':
                if (stack.size() == 0 || stack.back() != '{')
                    return false;
                else
                    stack.pop_back();
                break;
            case ']':
                if (stack.size() == 0 || stack.back() != '[')
                    return false;
                else
                    stack.pop_back();
                break;
            default:
                return false;
            }
        }
        if (stack.size() == 0)
            return true;
        return false;
    }
};

int main(void) {
    cout << Solution().isValid("(){}[]") << endl;

    system("pause");
    return 0;
}
