#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int redius = 0, pos = 0;
        for (auto house : houses) {
            if (house >= heaters[pos] - redius && house <= heaters[pos] + redius)
                continue;
            if (house < heaters[pos]) {
                redius = heaters[pos] - house;
            } else {
                while (pos + 1 < heaters.size() && heaters[pos + 1] < house) {
                    pos++;
                }
                if (pos + 1 < heaters.size() && heaters[pos + 1] - house < house - heaters[pos]) {
                    pos++;
                }
                redius = max(redius, abs(heaters[pos] - house));
            }
        }
        return redius;
    }
};

int main(void) {
    return 0;
}
