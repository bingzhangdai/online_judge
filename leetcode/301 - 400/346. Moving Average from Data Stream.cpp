#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class MovingAverage {
    int size;
    int sum;
    deque<int> window;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size(size), sum(0) {}
    
    double next(int val) {
        sum += val;
        window.push_back(val);
        if (window.size() > size)
            sum -= window.front(), window.pop_front();
        return 1.0 * sum / window.size();
    }
};

int main(void) {
    return 0;
}
