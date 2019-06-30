#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class MyCalendarThree {
    list<pair<int, char>> events;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int res = 0, count = 0;
        bool start_inserted = false, end_inserted = false;
        pair<int, char> s(start, 's'), e(end, 'e');
        for (auto it = events.begin(); it != events.end(); ++it) {
            if (!start_inserted && *it > s) {
                it = events.insert(it, s);
                start_inserted = true;
            }
            if (!end_inserted && *it > e) {
                it = events.insert(it, e);
                end_inserted = true;
            }
            if (it->second == 's')
                count++;
            else
                count--;
            res = max(res, count);
        }
        if (!start_inserted) {
            events.push_back(s);
            res = max(res, ++count);
        }
        if (!end_inserted) {
            events.push_back(e);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
