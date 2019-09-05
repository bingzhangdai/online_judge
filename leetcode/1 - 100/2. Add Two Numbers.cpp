#include <cstddef>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode((l1->val + l2->val) % 10);
        ListNode *curr = res;
        auto carry = (l1->val + l2->val) / 10;
        while (l1->next || l2->next) {
            auto sum = carry
                    + (l1->next ? (l1 = l1->next), l1->val : 0)
                    + (l2->next ? (l2 = l2->next), l2->val : 0);
            curr = (curr->next = new ListNode(sum % 10));
            carry = sum / 10;
        }
        if (carry)
            curr->next = new ListNode(carry);
        return res;
    }
};

int main(void) {
    return 0;
}
