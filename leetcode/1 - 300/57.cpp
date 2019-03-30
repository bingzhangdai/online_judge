#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool merged = false;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i].start, end = intervals[i].end;
            if (end < newInterval.start || start > newInterval.end)
                res.push_back(Interval(start, end));
            else {
                start = min(start, newInterval.start);
                end = max(end, newInterval.end);
                while (i + 1 < intervals.size() && intervals[i + 1].start <= end)
                    end = max(end, intervals[++i].end);
                res.push_back(Interval(start, end));
                merged = true;
            }
        }
        if (!merged)
            res.push_back(newInterval);
        sort(res.begin(), res.end(), [](Interval m, Interval n) {return m.start < n.start; });
        return res;
    }
};

int main(void) {
    auto intervals = vector<Interval>({ Interval(1,2), Interval(6,9) });
    auto newInterval = Interval(2,5);
    cout << Solution().insert(intervals, newInterval).size() << endl;
    // system("pause");
    return 0;
}
