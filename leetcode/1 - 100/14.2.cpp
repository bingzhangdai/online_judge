#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
            return "";
        int common = strs[0].length();
        for (int i = 1; i < strs.size() && common; i++) {
            int tmp;
            for (tmp = 0; tmp < common && tmp < strs[i].length() && strs[0][tmp] == strs[i][tmp]; tmp++);
            common = tmp;
        }
        return strs[0].substr(0, common);
    }
};

int main(void) {
    cout << Solution().longestCommonPrefix(vector<string>({"1234","123e"})) << endl;
    return 0;
}
