#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
    const int num = 26;
public:
    // Initialize your data structure here.
    vector<TrieNode *> next = vector<TrieNode *>(num, nullptr);
    vector<bool> is_leaf = vector<bool>(num, false);
    TrieNode() {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (word == "") {
            empty_str = true;
            return;
        }
        auto node = root;
        for (int i = 0; i < word.size() - 1; i++) {
            int n = word[i] - 'a';
            if (!node->next[n])
                node->next[n] = new TrieNode();
            node = node->next[n];
        }
        node->is_leaf[word.back() - 'a'] = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if (word == "")
            return empty_str;
        auto node = root;
        for (int i = 0; i < word.size() - 1; i++) {
            int n = word[i] - 'a';
            if (!node->next[n])
                return false;
            node = node->next[n];
        }
        return node->is_leaf[word.back() - 'a'];
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (prefix == "")
            return true;
        auto node = root;
        for (int i = 0; i < prefix.size() - 1; i++) {
            int n = prefix[i] - 'a';
            if (!node->next[n])
                return false;
            node = node->next[n];
        }
        int n = prefix.back() - 'a';
        return node->is_leaf[n] || node->next[n] != nullptr;
    }

private:
    bool empty_str = false;
    TrieNode* root;
};

int main(void) {
    Trie trie = Trie();
    trie.insert("somestring");
    cout << trie.search("some") << endl;
    cout << trie.startsWith("some") << endl;
    return 0;
}
