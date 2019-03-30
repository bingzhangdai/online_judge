#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Follow up:
Could you do this in one pass?
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head, *second = head;
        if (!head || n == 0) { return head; }
        while (n--) {
            second = second->next;
        }
        if (!second) {
            auto tmp = head->next;
            delete head;
            return tmp;
        }
        while (second->next) {
            second = second->next;
            first = first->next;
        }
        auto tmp = first->next->next;
        delete first->next;
        first->next = tmp;
        return head;
    }
};

int main(void) {
    return 0;
}
