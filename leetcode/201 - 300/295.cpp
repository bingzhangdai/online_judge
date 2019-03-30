#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    double median = 0;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (num < median)
            max_heap.push(num);
        else
            min_heap.push(num);
        if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else if (min_heap.size() < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        median = min_heap.size() == max_heap.size() ? (double)(min_heap.top() + max_heap.top()) / 2 : min_heap.top();
    }
    
    double findMedian() {
        return median;
    }
};

int main(void) {
    return 0;
}
