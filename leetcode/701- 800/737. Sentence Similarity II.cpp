#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_map<string, string> union_set;
    string find(const string& s) {
        if (!union_set.count(s))
            return union_set[s] = s;
        while (s != union_set[s])
            s = union_set[s];
        return s;
    }
    void join(string s, string t) {
        s = find(s), t = find(t);
        union_set[s] = t;
    }
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        for (const auto& p : pairs) {
            join(p[0], p[1]);
        }
        if (words1.size() != words2.size())
            return false;
        for (int i = 0; i < words1.size(); i++) {
            if (find(words1[i]) != find(words2[i]))
                return false;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
