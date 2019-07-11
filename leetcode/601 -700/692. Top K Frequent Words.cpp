#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
*/

class Solution {
    static const int max_child = 'z' - 'a' + 1;
    struct Trie {
        int count = 0;
        vector<Trie *> children = vector<Trie *>(max_child, nullptr);
    };
    Trie *root = new Trie;
    void traverse(Trie *node, string s, vector<pair<int, string>>& freq) {
        if (node->count)
            freq.emplace_back(node->count, s);
        for (int i = 0; i < max_child; i++) {
            if (node->children[i])
                s.push_back(i + 'a'), traverse(node->children[i], s, freq), s.pop_back();
        }
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (const auto& w : words) {
            auto curr = root;
            for (auto c : w) {
                if (!curr->children[c - 'a'])
                    curr->children[c - 'a'] = new Trie();
                curr = curr->children[c - 'a'];
            }
            curr->count++;
        }
        vector<pair<int, string>> freq;
        traverse(root, "", freq);
        partial_sort(freq.begin(), freq.begin() + k, freq.end(), [](const pair<int, string>& l, const pair<int, string>& r) {
            return l.first > r.first || l.first == r.first && l.second < r.second;
        });
        vector<string> res;
        for (auto i = 0; i < k; i++)
            res.push_back(freq[i].second);
        return res;
    }
};

int main(void) {
    return 0;
}
