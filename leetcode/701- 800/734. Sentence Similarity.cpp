#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_map<string, unordered_set<string>> hash_map;
    bool is_similar(const string& s, const string& t) {
        if (s == t)
            return true;
        return hash_map[s].find(t) != hash_map[s].end() ||
            hash_map[t].find(s) != hash_map[t].end();
    }
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        for (const auto& pair : pairs) {
            hash_map[pair[0]].insert(pair[1]);
            hash_map[pair[1]].insert(pair[0]);
        }
        if (words1.size() != words2.size())
            return false;
        for (int i = 0; i < words1.size(); i++) {
            if (!is_similar(words1[i], words2[i]))
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
