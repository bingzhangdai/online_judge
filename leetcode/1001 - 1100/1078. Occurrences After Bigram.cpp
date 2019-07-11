#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        auto input = first + ' ' + second + ' ';
        for (auto pos = text.find(input); pos != string::npos; pos = text.find(input, pos + 1)) {
            auto s = pos + input.length();
            if (s >= text.length())
                break;
            auto e = text.find(' ', s);
            res.push_back(e == string::npos ? text.substr(s) : text.substr(s, e - s));
        }
        return res;
    }
};

int main(void) {
    return 0;
}
