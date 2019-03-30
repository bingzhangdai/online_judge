#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        deque<string> p{};
        int i(0), j;
        path += "/";
        while ((j = path.find('/', i + 1)) != string::npos) {
            string s = path.substr(i, j - i);
            if (s == "/..") {
                if (p.size())
                    p.pop_back();
            }
            else if (s != "/." && s != "/")
                p.push_back(s);
            i = j;
        }
        if (p.size() == 0)
            return "/";
        for_each(p.begin(), p.end(), [&res](string& s) { res += s; });
        return res;
    }
};

int main(void) {
    cout << Solution().simplifyPath("/a/../b/./../c/") << endl;
    // system("pause");
    return 0;
}
