#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int dist = 0, last = -1, n = seats.size();
        for (auto i = 0; i < n; i++)
            if (seats[i])
                dist = last == -1 ? i : max(dist, (i - last) / 2),
                last = i;
        return max(dist, n - 1 - last);
    }
};

int main(void) {
    return 0;
}
