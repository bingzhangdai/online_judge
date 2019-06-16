#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
b a l l
a r e a
l e a d
l a d y
*/

class Solution {
    struct Trie {
        char c;
        unordered_map<char, Trie*> children;
        Trie(char c = ' ') : c(c) {}
    };
    Trie* root = new Trie();
    int depth = 0;
    void dfs(vector<vector<string>>& res, vector<string>& square, vector<Trie*>& nodes) {
        auto pos0 = 0;
        while (pos0 < depth) {
            if (square[pos0].length() != depth)
                break;
            pos0++;
        }
        if (pos0 == depth) {
            res.push_back(square);
            return;
        }
        auto pos1 = square[pos0].length();
        auto curr0 = nodes[pos0], curr1 = nodes[pos1];
        for (const auto& child : curr0->children) {
            if (curr1->children.find(child.first) != curr1->children.end()) {
                nodes[pos1] = curr1->children[child.first];
                square[pos1].push_back(child.first);
                if (pos1 != pos0) {
                    nodes[pos0] = child.second;
                    square[pos0].push_back(child.first);
                }
                dfs(res, square, nodes);
                nodes[pos1] = curr1;
                square[pos1].pop_back();
                if (pos1 != pos0) {
                    nodes[pos0] = curr0;
                    square[pos0].pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string> & words) {
        if (words.empty())
            return {};
        for (const auto& word : words) {
            auto curr = root;
            for (auto c : word) {
                if (curr->children.find(c) == curr->children.end())
                    curr->children[c] = new Trie(c);
                curr = curr->children[c];
            }
        }
        depth = words.front().length();
        vector<vector<string>> res;
        vector<string> square(depth, "");
        vector<Trie*> nodes(depth, root);
        dfs(res, square, nodes);
        return res;
    }
};

int main(void) {
    vector<string> words{ "area","lead","wall","lady","ball" };
    Solution().wordSquares(words);
    return 0;
}
