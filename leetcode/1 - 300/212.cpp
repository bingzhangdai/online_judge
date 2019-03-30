#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Example:
Input: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

struct Trie {
    char c;
    bool end = false;
    vector<Trie *> children = vector<Trie *>('z' - 'a' + 1, nullptr);
    explicit Trie(char c, bool end = false) :c(c), end(end) {
    }
};

class Solution {
    Trie *BuildTree(const vector<string>& words) {
        auto root = new Trie('*');
        for (const auto& word : words) {
            auto current = root;
            for (auto c : word) {
                auto i = c - 'a';
                if (!current->children[i])
                    current->children[i] = new Trie(c);
                current = current->children[i];
            }
            current->end = true;
        }
        return root;
    }
    void DeleteTree(Trie *root) {
        for (auto& child : root->children) {
            if (child)
                DeleteTree(child);
        }  
        delete root;
    }
    void dfs(vector<string>& res, vector<vector<char>>& board, Trie *root, int i, int j, string path) {\
        if (!root || board[i][j] != root->c)
            return;
        path += root->c;
        if (root->end) {
            root->end = false;
            res.push_back(path);
        }
        // cout << path << endl;
        board[i][j] = '*';
        auto m = board.size(), n = board[0].size();
        if (i > 0 && board[i - 1][j] != '*')
            dfs(res, board, root->children[board[i - 1][j] - 'a'], i - 1, j, path);
        if (i < m - 1 && board[i + 1][j] != '*')
            dfs(res, board, root->children[board[i + 1][j] - 'a'], i + 1, j, path);
        if (j > 0 && board[i][j - 1] != '*')
            dfs(res, board, root->children[board[i][j - 1] - 'a'], i, j - 1, path);
        if (j < n - 1 && board[i][j + 1] != '*')
            dfs(res, board, root->children[board[i][j + 1] - 'a'], i, j + 1, path);
        board[i][j] = root->c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto root = BuildTree(words);
        vector<string> res;
        auto m = board.size(), n = board[0].size();
        for (auto i = 0; i < m; i++)
            for (auto j = 0; j < n; j++) {
                dfs(res, board, root->children[board[i][j] - 'a'], i, j, "");
            }
        DeleteTree(root);
        return res;
    }
};

int main(void) {
    vector<string> words = {"bbaabaabaaaaabaababaaaaababb","aabbaaabaaabaabaaaaaabbaaaba","babaababbbbbbbaabaababaabaaa","bbbaaabaabbaaababababbbbbaaa","babbabbbbaabbabaaaaaabbbaaab","bbbababbbbbbbababbabbbbbabaa","babababbababaabbbbabbbbabbba","abbbbbbaabaaabaaababaabbabba","aabaabababbbbbbababbbababbaa","aabbbbabbaababaaaabababbaaba","ababaababaaabbabbaabbaabbaba","abaabbbaaaaababbbaaaaabbbaab","aabbabaabaabbabababaaabbbaab","baaabaaaabbabaaabaabababaaaa","aaabbabaaaababbabbaabbaabbaa","aaabaaaaabaabbabaabbbbaabaaa","abbaabbaaaabbaababababbaabbb","baabaababbbbaaaabaaabbababbb","aabaababbaababbaaabaabababab","abbaaabbaabaabaabbbbaabbbbbb","aaababaabbaaabbbaaabbabbabab","bbababbbabbbbabbbbabbbbbabaa","abbbaabbbaaababbbababbababba","bbbbbbbabbbababbabaabababaab","aaaababaabbbbabaaaaabaaaaabb","bbaaabbbbabbaaabbaabbabbaaba","aabaabbbbaabaabbabaabababaaa","abbababbbaababaabbababababbb","aabbbabbaaaababbbbabbababbbb","babbbaabababbbbbbbbbaabbabaa"};
    vector<vector<char>> board = {{'b','a','a','b','a','b'},
                                  {'a','b','a','a','a','a'},
                                  {'a','b','a','a','a','b'},
                                  {'a','b','a','b','b','a'},
                                  {'a','a','b','b','a','b'},
                                  {'a','a','b','b','b','a'},
                                  {'a','a','b','a','a','b'}};
    cout << Solution().findWords(board, words).size() << endl;
    return 0;
}
