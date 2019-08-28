#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    struct Trie {
        unordered_map<char, Trie *> children;
        bool leaf = false;
    };
    Trie *root = new Trie();
    int check(const string& s, int i) {
        auto curr = root;
        auto res = -1;
        for (;i < s.length();i++) {
            if (!curr->children.count(s[i]))
                break;
            curr = curr->children[s[i]];
            if (curr->leaf)
                res = i;
        }
        return res;
    }
public:
    string addBoldTag(string s, vector<string>& dict) {
        for (const auto& w : dict) {
            auto curr = root;
            for (auto c : w) {
                if (!curr->children.count(c))
                    curr->children[c] = new Trie();
                curr = curr->children[c];
            }
            curr->leaf = true;
        }
        string res = "";
        int start = -1, end = -1;
        for (int i = 0; i < s.length(); i++) {
            auto next = check(s, i);
            if (next != -1) {
                if (start == -1)
                    start = i, end = next;
                else
                    end = max(end, next);
            }
            else {
                if (start == -1)
                    res.push_back(s[i]);
                else if (i > end)
                    res += "<b>" + s.substr(start, end - start + 1) + "</b>",
                    res.push_back(s[i]),
                    start = end = -1;
            }
        }
        if (start != -1)
            res += "<b>" + s.substr(start, end - start + 1) + "</b>";
        return res;
    }
};

int main(void) {
    return 0;
}
