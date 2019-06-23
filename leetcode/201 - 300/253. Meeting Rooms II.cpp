#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, char>> time;
        for (const auto& interval : intervals) {
            // 'e' < 's' is also important, hhh
            time.emplace_back(interval[0], 's');
            time.emplace_back(interval[1], 'e');
        }
        sort(time.begin(), time.end());
        int rooms = 0, current = 0;
        for (const auto& t : time) {
            if (t.second == 'e')
                current--;
            else
                current++;
            rooms = max(rooms, current);
        }
        return rooms;
    }
};

int main(void) {
    return 0;
}
