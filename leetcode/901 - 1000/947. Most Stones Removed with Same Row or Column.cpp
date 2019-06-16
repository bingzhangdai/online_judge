#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
A stone, connect a row index and col.

Have this idea in mind, the solution can be much simpler.
The number of islands of points,
is the same as the number of islands of indexes.
*/

class Solution {
    unordered_map<int, int> hash_map;
    int num_islands = 0;
    int find(int x) {
        if (hash_map.find(x) == hash_map.end())
            return num_islands++, hash_map[x] = x;
        while (x != hash_map[x])
            x = hash_map[x];
        return x;
    }
    void join(int x, int y) {
        x = find(x), y = find(y);
        if (x != y)
            hash_map[x] = y, num_islands--;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        for (const auto& stone : stones) {
            join(stone[0], ~stone[1]);
        }
        return stones.size() - num_islands;
    }
};

int main(void) {
    return 0;
}
