#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple>
using namespace std;

class Solution {
    vector<string> res;
    void dfs(int num, int curr, int index) {
        if (curr / 64 >= 12 || curr % 64 >= 60)
            return;
        if (num == 0) {
            auto minute = to_string(curr % 64);
            if (minute.size() == 1)
                minute = "0" + minute;
            res.push_back(to_string(curr / 64) + ":" + minute);
            return;
        }
        for (int i = index; i >= num - 1; i--) {
            dfs(num - 1, curr + (1 << i), i - 1);
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        dfs(num, 0, 9);
        return res;
    }
};

int main(void) {
    return 0;
}
