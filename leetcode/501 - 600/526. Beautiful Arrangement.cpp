#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int res = 0;

    void dfs(vector<int>& array, int curr, int N) {
        if (curr > N) {
            res++;
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (array[i] != 0 || i % curr && curr % i)
                continue;
            array[i] = i;
            dfs(array, curr + 1, N);
            array[i] = 0;
        }
    }

public:
    int countArrangement(int N) {
        vector<int> array(N + 1, 0);
        dfs(array, 1, N);
        return res;
    }
};

int main(void) {
    return 0;
}
