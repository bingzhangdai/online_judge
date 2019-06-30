#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    list<pair<int, int>> events = list<pair<int, int>>();
    bool book(int start, int end) {
        auto it = lower_bound(events.begin(), events.end(), pair<int, int>(start, start));
        if (it != events.end()) {
            if (it->first < end)
                return false;
        }
        if (it != events.begin()) {
            --it;
            if (it->second > start)
                return false;
            ++it;
        }
        events.insert(it, pair<int, int>(start, end));
        return true;
    }
};

int main(void) {
    return 0;
}
