#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    inline bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }
    string strip(const string& s) {
        int i(0);
        while (i < s.size() && s[i] == ' ')
            i++;
        string res = s.substr(i, s.size() - i);
        if (res == "")
            return res;
        i = res.size() - 1;
        while (i >= 0 && res[i] == ' ')
            i--;
        return res.substr(0, i + 1);
    }
    inline string noSign(const string& s) {
        return (s[0] == '+' || s[0] == '-') ? s.substr(1, s.size() - 1) : s;
    }
    bool isInt(const string& s) {
        string tmp = noSign(s);
        return isUnsignInt(tmp);
    }
    bool isUnsignInt(const string& s) {
        int i = 0;
        if (s == "")
            return false;
        while (i < s.size() && isDigit(s[i]))
            i++;
        if (i == s.size())
            return true;
        return false;
    }
    // .1, 1., 1.1, 1
    bool isFloat(const string& s) {
        string tmp = noSign(s);
        return isUnsignFloat(tmp);
    }
    bool isUnsignFloat(const string& s) {
        int i = 0;
        if (s == "")
            return false;
        while (i < s.size() && isDigit(s[i]))
            i++;
        if (i == s.size())
            return true;
        if (s[i] != '.')
            return false;
        string former = s.substr(0, i);
        if (i == s.size() - 1) {
            return former != "";
        }
        string latter = s.substr(i + 1, s.size() - i - 1);
        return isUnsignInt(latter);
    }
    // .1e10
    bool isScientific(const string& s) {
        int i = 0;
        string tmp = noSign(s);
        if (tmp == "")
            return false;
        while (i < tmp.size() && (isDigit(tmp[i]) || tmp[i] == '.'))
            i++;
        if (i == tmp.size() || i == tmp.size() - 1 || tmp[i] != 'e')
            return false;
        string former(tmp.substr(0, i)), latter(tmp.substr(i + 1, tmp.size() - i - 1));
        return isUnsignFloat(former) && isInt(latter);
    }
public:
    bool isNumber(string s) {
        s = strip(s);
        return isFloat(s) || isScientific(s);
    }
};

int main(void) {
    string s;
    cin >> s;
    cout << Solution().isNumber(s) << endl;
    // system("pause");
    return 0;
}
