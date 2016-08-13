#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_table;
        for (const auto& i : strs) {
            auto tmp = i;
            sort(tmp.begin(), tmp.end());
            hash_table[tmp].push_back(i);
        }
        vector<vector<string>> res(hash_table.size());
        int i = 0;
        for (auto it = hash_table.begin(); it != hash_table.end(); ++it) {
            res[i].swap(it->second);
            sort(res[i].begin(), res[i].end());
            i++;
        }
        return res;
    }
};

int main(void) {
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    cout << Solution().groupAnagrams(strs).size() << endl;
    // system("pause");
    return 0;
}
