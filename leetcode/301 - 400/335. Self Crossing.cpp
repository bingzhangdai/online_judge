#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/*
For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
*/

class SummaryRanges {
    struct cmp {
        bool operator()(const Interval& left, const Interval& right) const {
            return left.start < right.start;
        }
    };

    set<Interval, cmp> intervals_;
public:
    /** Initialize your data structure here. */
    SummaryRanges() { }

    void addNum(int val) {
        auto interval = Interval(val, val);
        auto pos = intervals_.lower_bound(Interval(val, val));
        auto pos_after = pos;

        if (pos != intervals_.begin())
            --pos;
        else
            pos = intervals_.end();

        if (pos != intervals_.end() && pos_after != intervals_.end() &&
            val == pos->end + 1 && val == pos_after->start - 1) {
            interval.start = pos->start;
            interval.end = pos_after->end;
            pos = intervals_.erase(pos);
            intervals_.erase(pos);
            intervals_.insert(interval);
        }
        else if (pos != intervals_.end() && val == pos->end + 1) {
            interval.start = pos->start;
            intervals_.erase(pos);
            intervals_.insert(interval);
        }
        else if (pos_after != intervals_.end() && val == pos_after->start - 1) {
            interval.end = pos_after->end;
            intervals_.erase(pos_after);
            intervals_.insert(interval);
        }
        else if (pos != intervals_.end() && val <= pos->end || pos_after != intervals_.end() && val == pos_after->start)
            return;
        else
            intervals_.insert(interval);
    }

    vector<Interval> getIntervals() {
        return vector<Interval>(intervals_.begin(), intervals_.end());
    }
};

int main(void) {
    return 0;
}
