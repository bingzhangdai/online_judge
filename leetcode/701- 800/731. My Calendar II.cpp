#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class MyCalendarTwo {
    map<int, int> events;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        int count = 0;
        events[start]++, events[end]--;
        for (const auto& p : events) {
            count += p.second;
            if (count >= 3)
                return events[start]--, events[end]++, false;
        }
        return true;
    }
};


int main(void) {
    return 0;
}
