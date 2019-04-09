#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 26;

class MagicDictionary {

    struct Trie {
        char c;
        vector<Trie *> next = vector<Trie *>(SIZE, nullptr);
        bool is_leaf = false;
        Trie(char c = '*') : c(c) {}
    };

    Trie* root = new Trie('*');

    bool search(const string& word, int ind, Trie* curr, bool is_modified = false) {
        if (is_modified) {
            while (ind < word.length()) {
                if (!curr || !curr->next[word[ind] - 'a'])
                    return false;
                curr = curr->next[word[ind] - 'a'];
                ind++;
            }
            return curr->is_leaf;
        }
        if (ind >= word.length() || !curr)
            return false;
        for (auto next : curr->next) {
            if (!next)
                continue;
            if (next->c == word[ind] && search(word, ind + 1, next, false))
                return true;
            if (next->c != word[ind] && search(word, ind + 1, next, true))
                return true;
        }
        return false;
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const auto& word : dict) {
            auto curr = root;
            for (auto c : word) {
                if (curr->next[c - 'a'] == nullptr)
                    curr->next[c - 'a'] = new Trie(c);
                curr = curr->next[c - 'a'];
            }
            curr->is_leaf = true;
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return search(word, 0, root);
    }
};

int main(void) {
    return 0;
}
