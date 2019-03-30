#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        int i = 0, j = 0;
        bool first_op = true;
        while(i < s.size()) {
            if (s[i] == ' ')
                i++;
            else if (s[i] == '(') {
                first_op = true;
                op.push(s[i++]);
            }
            else if (s[i] == '+' || s[i] == '-') {
                op.push(s[i++]);
                if (first_op)
                    num.push(0);
                first_op = false;
            }
            else {
                int n;
                if (s[i] == ')') {
                    n = num.top();
                    num.pop();
                    op.pop();
                    i++;
                }
                else {
                    for(j = i + 1; j < s.size() && s[j] >= '0' && s[j] <= '9'; j++);
                    n = stoi(s.substr(i, j - i));
                    i = j;
                }
                while (!op.empty() && (op.top() == '+' || op.top() == '-')) {
                    if (op.top() == '+')
                        n += num.top();
                    else
                        n = num.top() - n;
                    num.pop();
                    op.pop();
                }
                num.push(n);
                first_op = false;
            }
        }
        return num.top();
    }
};

int main(void) {
    // cout << stoi(" -1 ") << endl;
    cout << Solution().calculate(" (-1+(4+5+2)-3)+( 6 + 8 )   ") << endl;
    return 0;
}
