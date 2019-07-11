#include <iostream>
#include <vector>
using namespace std;

class Solution {
    struct Trie {
        char val;
        vector<int> next = vector<int>(26, -1);
        bool unique = true;
    };

    vector<Trie> nodes = vector<Trie>(50);
    int count = 1;

    int new_node(char val) {
        if (count == nodes.size())
            nodes.resize(nodes.size() + 50);
        nodes[count].val = val;
        return count++;
    }

    void free() {
        for (auto& node : nodes) {
            node.unique = true;
            for (auto i = 0; i < node.next.size(); i++)
                node.next[i] = -1;
        }
        count = 1;
    }

    void insert(const string& word) {
        auto curr = 0;
        for (auto c : word) {
            if (nodes[curr].next[c - 'a'] == -1)
                nodes[curr].next[c - 'a'] = new_node(word.back());
            else
                nodes[nodes[curr].next[c - 'a']].unique = false;
            curr = nodes[curr].next[c - 'a'];
        }
    }

    string get_abbr(const string& word) {
        string abbr = "";
        auto curr = 0;
        for (auto i = 0; i < word.length(); i++) {
            abbr.push_back(word[i]);
            curr = nodes[curr].next[word[i] - 'a'];
            if (nodes[curr].unique) {
                auto rem = word.length() - i - 2;
                if (rem <= 1)
                    return word;
                return abbr + to_string(rem) + word.back();
            }
        }
        return word;
    }

public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> res(dict.size());
        unordered_map<string, vector<int>> abbrs;

        for (auto i = 0; i < dict.size(); i++) {
            const auto& word = dict[i];
            auto abbr = word.front() + to_string(word.length() - 2) + word.back();
            if (abbr.length() >= word.length())
                abbr = word;
            abbrs[res[i] = abbr].push_back(i);
        }

        for (const auto& p : abbrs) {
            if (p.second.size() <= 1)
                continue;
            for (auto i : p.second)
                insert(dict[i]);
            for (auto i : p.second)
                res[i] = get_abbr(dict[i]);
            free();
        }
        return res;
    }
};

int main(void) {
    return 0;
}
