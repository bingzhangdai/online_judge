#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& s, const string& t) {
            auto i = s.find(' ') + 1, j = t.find(' ') + 1;
            // all of the letter-logs come before any digit-log
            if (!isdigit(s[i]) && isdigit(t[j]))
                return true;
            if (isdigit(s[i]) && !isdigit(t[j]))
                return false;
            // The digit-logs should be put in their original order.
            if (isdigit(s[i]) && isdigit(t[j]))
                return false;
            auto logs_s = s.substr(i), logs_t = t.substr(j);
            // letter-logs are ordered lexicographically ignoring identifier
            if (logs_s != logs_t)
                return logs_s < logs_t;
            // with the identifier used in case of ties
            return s.substr(0, i) < t.substr(0, j);
        });
        return logs;
    }
};

int main(void) {
    return 0;
}
