#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0), res;
        queue<int> que;
        for (const auto& course_pair : prerequisites) {
            graph[course_pair.second].push_back(course_pair.first);
            indegree[course_pair.first]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                que.push(i);
        }
        while (!que.empty()) {
            auto i = que.front();
            que.pop();
            res.push_back(i);
            for (const auto j : graph[i]) {
                if (--indegree[j] == 0)
                    que.push(j);
            }
        }
        for (const auto i : indegree)
            if (i != 0)
                return vector<int>();
        return res;
    }
};

int main(void) {
    return 0;
}
