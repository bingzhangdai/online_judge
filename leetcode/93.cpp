#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    void dfs(const string& s, int ind, vector<string>& path, vector<string>& res) {
        if (path.size() == 4) {
            if (ind == s.size())
                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        }
        if ((4 - path.size()) * 3 < s.size() - ind)
            return;
        for (int i = 1; i <= 3 && i + ind <= s.size(); i++) {
            auto num = s.substr(ind, i);
            if (i == 3 && stoi(num) > 255 || i > 1 && num[0] == '0')
                break;
            path.push_back(num);
            dfs(s, ind + i, path, res);
            path.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, path;
        dfs(s, 0, path, res);
        return res;
    }
};

int main(void) {
    cout << Solution().restoreIpAddresses("25525511135").size() << endl;
    // system("pause");
    return 0;
}
/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135", 
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/