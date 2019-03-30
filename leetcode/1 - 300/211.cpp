#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

const int num = 26;
class WordDictionary {
    struct TrieNode {
        vector<TrieNode *> next = vector<TrieNode *>(num, nullptr);
        vector<bool> is_leaf = vector<bool>(num, false);
    };
    bool is_empty_str = false;
    TrieNode *root = new TrieNode();
    bool search_with_regex(string word, int ind, TrieNode *node) {
        for (int i = ind; i < word.size() - 1; i++) {
            if (word[i] == '.') {
                bool res = false;
                for (int j = 0; j < num; j++)
                    if (node->next[j])
                        res = res || search_with_regex(word, i + 1, node->next[j]);
                return res;
            }
            auto n = word[i] - 'a';
            if (!node->next[n])
                return false;
            node = node->next[n];
        }
        if (word.back() == '.') {
            for (const auto lf : node->is_leaf)
                if (lf)
                    return true;
            return false;
        }
        return node->is_leaf[word.back() - 'a'];
    }
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        if (word == "") {
            is_empty_str = true;
            return;
        }
        auto node = root;
        for (int i = 0; i < word.size() - 1; i++) {
            auto n = word[i] - 'a';
            if (!node->next[n])
                node->next[n] = new TrieNode();
            node = node->next[n];
        }
        node->is_leaf[word.back() - 'a'] = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_with_regex(word, 0, root);
    }
};

int main(void) {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad") << endl;
    cout << wordDictionary.search("bad") << endl;
    cout << wordDictionary.search(".ad") << endl;
    cout << wordDictionary.search("b..") << endl;
    return 0;
}
