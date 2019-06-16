#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class AutocompleteSystem {
    struct Trie {
        char c;
        int count = 0;
        unordered_map<char, Trie *> children;
        Trie(char c = ' '): c(c) {}
    };
    Trie *root;
    Trie *curr;
    string curr_input = "";
    void dfs(vector<pair<string, int>>& res, Trie *node, string path) {
        if (node->count)
            res.emplace_back(path, node->count);
        for (const auto& p : node->children) {
            dfs(res, p.second, path + p.first);
        }
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        curr = root = new Trie();
        for (int i = 0; i < sentences.size(); i++) {
            const auto& sentence = sentences[i];
            auto tmp = root;
            for (auto c : sentence) {
                if (!tmp->children[c])
                    tmp->children[c] = new Trie(c);
                tmp = tmp->children[c];
            }
            tmp->count += times[i];
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            curr->count++;
            curr = root;
            curr_input = "";
            return {};
        }
        if (!curr->children[c])
            curr->children[c] = new Trie(c);
        curr_input += c;
        curr = curr->children[c];
        vector<pair<string, int>> res;
        dfs(res, curr, curr_input);
        sort(res.begin(), res.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        });
        vector<string> result;
        for (int i = 0; i < 3 && i < res.size(); i++) {
            result.push_back(res[i].first);
        }
        return result;
    }
};

int main(void) {
    return 0;
}
