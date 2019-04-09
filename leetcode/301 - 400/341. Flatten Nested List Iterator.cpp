#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
class NestedIterator {
    stack<NestedInteger> status;
    void push(const vector<NestedInteger>& nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            status.push(*it);
        }
    }
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        push(nestedList);
    }

    int next() {
        if (status.empty()) return 0;
        // const auto& integer = status.top();
        const auto integer = status.top();
        status.pop();
        if (integer.isInteger())
            return integer.getInteger();
        push(integer.getList());
        return next();
    }

    bool hasNext() {
        return !status.empty();
    }
};
*/

class NestedIterator {
    stack<NestedInteger> status;
    void push(const vector<NestedInteger>& nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            status.push(*it);
        }
        while (!status.empty() && !status.top().isInteger()) {
            const auto integer = status.top();
            status.pop();
            push(integer.getList());
        }
    }
    void push(const NestedInteger& nestedInteger) {
        push(nestedInteger.getList());
    }
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        push(nestedList);
    }

    int next() {
        if (status.empty()) return 0;
        // const auto& integer = status.top();
        const auto integer = status.top();
        status.pop();
        
    }

    bool hasNext() {
        return !status.empty();
    }
};

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

int main(void) {
    return 0;
}
