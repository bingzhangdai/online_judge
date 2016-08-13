#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string common = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < strs[i].size() && j < common.length() && strs[i][j] == common[j]) { j++; }
            common = common.substr(0, j);
        }
        return common;
    }
};

int main(void) {
    cout << Solution().longestCommonPrefix(vector<string>({"1234","123e"})) << endl;

    system("pause");
    return 0;
}
