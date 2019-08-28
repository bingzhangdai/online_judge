#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: 
["9001 discuss.leetcode.com"]
Output: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
*/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for (const auto& cp : cpdomains) {
            auto i = cp.find(' ');
            auto c = stoi(cp.substr(0, i));
            auto d = cp.substr(i + 1);
            count[d] += c;
            for (i = d.find('.'); i != string::npos; i = d.find('.', i + 1)) {
                count[d.substr(i + 1)] += c;
            }
        }
        vector<string> res;
        for (const auto& cp : count) {
            res.push_back(to_string(cp.second) + ' ' + cp.first);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
