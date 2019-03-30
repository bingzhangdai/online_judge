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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), [](Interval m, Interval n){ return m.start < n.start; });
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            while (i + 1 < intervals.size() && intervals[i + 1].start <= end) {
                end = max(end, intervals[++i].end);
            }
            res.push_back(Interval(start, end));
        }
        return res;
    }
};

int main(void) {
    auto intervals = vector<Interval>({ Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18) });
    cout << Solution().merge(intervals).size() << endl;
    // system("pause");
    return 0;
}
