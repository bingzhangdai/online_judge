#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> stk, min_stk;
public:
    MinStack() {}
    
    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.top())
            min_stk.push(x);
    }
    
    void pop() {
        if (min_stk.top() == stk.top())
            min_stk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

int main(void) {
    return 0;
}
