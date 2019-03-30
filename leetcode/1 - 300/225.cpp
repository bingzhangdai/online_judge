#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Stack {
    queue<int> que;
    int back;
public:
    // Push element x onto stack.
    void push(int x) {
        back = x;
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = que.size();
        while (--n) {
            back = que.front();
            que.push(que.front());
            que.pop();
        }
        que.pop();
    }

    // Get the top element.
    int top() {
        return back;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};

int main(void) {
    auto s = Stack();
    s.push(1);
    s.push(2);
    s.top();
    return 0;
}
