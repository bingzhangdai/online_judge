#include <iostream>
#include <deque>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        deque<int> num;
        deque<char> op;
        int i = 0, j = 0;
        while (i < s.size()) {
            if (s[i] == ' ')
                i++;
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (num.empty())
                    num.push_back(0);
                op.push_back(s[i++]);
            }
            else {
                for (j = i; j < s.size() && s[j] >= '0' && s[j] <= '9'; j++);
                int res = stoi(s.substr(i, j - i));
                i = j;
                if (!op.empty() && (op.back() == '*' || op.back() == '/')) {
                    if (op.back() == '*')
                        res *= num.back();
                    else
                        res = num.back() / res;
                    num.pop_back();
                    op.pop_back();
                }
                num.push_back(res);
            }
        }
        int res = num.front();
        num.pop_front();
        while (!op.empty()) {
            if (op.front() == '+')
                res += num.front();
            else
                res -= num.front();
            num.pop_front();
            op.pop_front();
        }
        return res;
    }
};

int main(void) {
    cout << Solution().calculate("  -3 + 4 -5/2*3     ") << endl;
    return 0;
}
