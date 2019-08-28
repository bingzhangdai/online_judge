#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<>> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for (auto i : nums) {
            heap.push(i);
            if (heap.size() > k)
                heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > k)
            heap.pop();
        return heap.top();
    }
};

int main(void) {
    return 0;
}
