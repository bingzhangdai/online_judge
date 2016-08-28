#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

/*
// DFS, Time Limit Exceeded, TAT
class Solution {
    int distance(const string& word1, const string& word2) {
        auto count = 0;
        for (int i = 0; i < word1.size(); i++)
            if (word1[i] != word2[i])
                count++;
        return count;
    }
    void dfs(vector<string>& word_list, vector<bool>& visited, const vector<vector<int>>& adj_list, vector<string>& path, vector<vector<string>>& res, int pre) {
        if (!adj_list[pre].empty() && adj_list[pre].back() == word_list.size() - 1) {
            path.push_back(word_list.back());
            if (res.empty() || res[0].size() == path.size())
                res.push_back(path);
            else {
                res.clear();
                res.push_back(path);
            }
            path.pop_back();
            return;
        }
        if (adj_list[pre].empty() || !res.empty() && res[0].size() < path.size() + 2)
            return;
        
        for (auto i : adj_list[pre]) {
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(word_list[i]);
                dfs(word_list, visited, adj_list, path, res, i);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        vector<string> path { beginWord }, word_list_vector { beginWord };
        
        for (auto it = wordList.begin(); it != wordList.end(); ++it)
            word_list_vector.push_back(*it);
        word_list_vector.push_back(endWord);
        
        vector<bool> visited(word_list_vector.size(), false);
        vector<vector<int>> adj_list(word_list_vector.size(), vector<int>());
        for (int i = 0; i < word_list_vector.size(); i++)
            for (int j = i + 1; j < word_list_vector.size(); j++)
                if (distance(word_list_vector[i], word_list_vector[j]) == 1) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }

        
        dfs(word_list_vector, visited, adj_list, path, res, 0);
        return res;
    }
};
*/

/*
// BFS, 有一定概率不超时，所以，还是不行
class Solution {
    int distance(const string& word1, const string& word2) {
        auto count = 0;
        for (int i = 0; i < word1.size(); i++)
            if (word1[i] != word2[i])
                count++;
        return count;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
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
        
        vector<vector<vector<string>>> res(word_list_vector.size());
        res[0].push_back({ {beginWord} });

        // use bfs instead
        std::queue<int> bfs_queue;
        bfs_queue.push(0);
        unordered_set<int> bfs_next_enqueue;
        while (!bfs_queue.empty()) {
            auto ind = bfs_queue.front();
            bfs_queue.pop();
            if (ind == word_list_vector.size() - 1)
                return res[ind];
            
            for (auto i : adj_list[ind]) {
                if (!visited[i]) {
                    for (auto path : res[ind]) {
                        path.push_back(word_list_vector[i]);
                        res[i].push_back(path);
                    }
                    bfs_next_enqueue.insert(i);
                }
            }

            if (bfs_queue.empty()) {
                for (auto i : bfs_next_enqueue) {
                    visited[i] = true;
                    bfs_queue.push(i);
                }
                bfs_next_enqueue.clear();
            }
        }

        return res[word_list_vector.size() - 1];
    }
};
*/

/*
// BFS + DFS, 还是要超时，*了狗
class Solution {
    int distance(const string& word1, const string& word2) {
        auto count = 0;
        for (int i = 0; i < word1.size(); i++)
            if (word1[i] != word2[i])
                count++;
        return count;
    }
    void dfs(vector<string>& word_list, vector<bool>& visited, const vector<vector<bool>>& adj_matrix, vector<string>& path, vector<vector<string>>& res, int pre) {
        if (pre == word_list.size() - 1) {
            if (!res.empty() && res[0].size() > path.size())
                res.clear();
            res.push_back(path);
            return;
        }
        if (!res.empty() && res[0].size() < path.size() + 1)
            return;
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i] && adj_matrix[i][pre]) {
                path.push_back(word_list[i]);
                visited[i] = true;
                dfs(word_list, visited, adj_matrix, path, res, i);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<string> word_list_vector { beginWord };
        for (auto it = wordList.begin(); it != wordList.end(); ++it)
            word_list_vector.push_back(*it);
        word_list_vector.push_back(endWord);
        
        vector<bool> visited(word_list_vector.size(), false);
        visited[0] = true;

        vector<vector<bool>> adj_matrix(word_list_vector.size(), vector<bool>(word_list_vector.size(), false));
        for (int i = 0; i < word_list_vector.size(); i++)
            for (int j = i + 1; j < word_list_vector.size(); j++)
                if (distance(word_list_vector[i], word_list_vector[j]) == 1) {
                    adj_matrix[i][j] = adj_matrix[j][i] = true;
                }

        // use bfs, to remove loops in the graph
        std::queue<int> bfs_queue;
        bfs_queue.push(0);
        unordered_set<int> bfs_next_enqueue;
        while (!bfs_queue.empty()) {
            auto ind = bfs_queue.front();
            bfs_queue.pop();
            
            for (int i = 0; i < word_list_vector.size(); i++) {
                if (adj_matrix[i][ind] && visited[i])
                    adj_matrix[i][ind] = adj_matrix[ind][i] = false;
            }

            if (bfs_queue.empty()) {
                for (auto i : bfs_next_enqueue) {
                    visited[i] = true;
                    bfs_queue.push(i);
                }
                bfs_next_enqueue.clear();
            }
        }

        // dfs
        for (int i = 1; i < visited.size(); i++)
            visited[i] = false;
        vector<string> path { beginWord };
        vector<vector<string>> res;
        dfs(word_list_vector, visited, adj_matrix, path, res, 0);

        return res;
    }
};
*/

class Solution {
public:
class Solution {
    int distance(const string& word1, const string& word2) {
        auto count = 0;
        for (int i = 0; i < word1.size(); i++)
            if (word1[i] != word2[i])
                count++;
        return count;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
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
        
        vector<vector<int>> pre;

        std::queue<int> bfs_queue;
        bfs_queue.push(0);
        unordered_set<int> bfs_next_enqueue;
        while (!bfs_queue.empty()) {
            auto ind = bfs_queue.front();
            bfs_queue.pop();
            if (ind == word_list_vector.size() - 1)
                break;
            
            for (auto i : adj_list[ind]) {
                if (!visited[i]) {
                    pre[i].push_back(ind);
                    bfs_next_enqueue.insert(i);
                }
            }

            if (bfs_queue.empty()) {
                for (auto i : bfs_next_enqueue) {
                    visited[i] = true;
                    bfs_queue.push(i);
                }
                bfs_next_enqueue.clear();
            }
        }

        vector<vector<string>> res;
    }
};

int main(void) {
    unordered_set<string> wordList { "hot","dot","dog","lot","log" };
    cout << Solution().findLadders("hit", "cog", wordList).size() << endl;
    return 0;
}
