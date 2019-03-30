#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
    int distance(const string& word1, const string& word2) {
        auto count = 0;
        for (int i = 0; i < word1.size(); i++)
            if (word1[i] != word2[i])
                count++;
        return count;
    }
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        vector<string> word_list_vector { beginWord };
        for (auto it = wordList.begin(); it != wordList.end(); ++it)
            word_list_vector.push_back(*it);
        word_list_vector.push_back(endWord);
        
        vector<bool> visited(word_list_vector.size(), false);
        visited[0] = true;

        vector<vector<int>> adj_list(word_list_vector.size(), vector<int>());
        for (int i = 0; i < word_list_vector.size(); i++)
            for (int j = i + 1; j < word_list_vector.size(); j++)
                if (distance(word_list_vector[i], word_list_vector[j]) == 1) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
        
        int level = 0;
        std::queue<int> bfs_queue;
        bfs_queue.push(0);
        unordered_set<int> bfs_next_enqueue;
        while (!bfs_queue.empty()) {
            auto ind = bfs_queue.front();
            bfs_queue.pop();
            if (ind == word_list_vector.size() - 1)
                return level + 1;
            
            for (auto i : adj_list[ind]) {
                if (!visited[i]) {
                    bfs_next_enqueue.insert(i);
                }
            }

            if (bfs_queue.empty()) {
                for (auto i : bfs_next_enqueue) {
                    visited[i] = true;
                    bfs_queue.push(i);
                }
                bfs_next_enqueue.clear();
                level++;
            }
        }

        return 0;
    }
};

int main(void) {
    unordered_set<string> wordList { "hot","dot","dog","lot","log" };
    cout << Solution().ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
