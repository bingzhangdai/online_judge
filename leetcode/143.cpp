#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// so elegant, lol
class Solution {
public:
    void reorderList(ListNode* head) {
        auto fast = head, slow = head;
        // find the middle of the linked list
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!slow || !slow->next)
            return;
        // reverse the right half linked list
        auto right_half_head = slow;
        auto next = right_half_head->next;
        slow->next = nullptr;
        while (next != nullptr) {
            auto tmp = next->next;
            next->next = right_half_head;
            right_half_head = next;
            next = tmp;
        }
        // merge tow list
        while (head != right_half_head && right_half_head) {
            auto left_next = head->next, right_next = right_half_head->next;
            head->next = right_half_head;
            right_half_head->next = left_next;
            head = left_next;
            right_half_head = right_next;
        }
        head->next = nullptr;
    }
};

int main(void) {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution().reorderList(head);
    return 0;
}
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→… 
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/
