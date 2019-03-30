#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode tmpL = ListNode(-1), tmpR = ListNode(-1);
        ListNode *headL = &tmpL, *left = headL, *headR = &tmpR, *right = headR;
        while (head != nullptr) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            }
            else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        left->next = headR->next;
        head = headL->next;
        return head;
    }
};

int main(void) {
    auto head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    cout << Solution().partition(head, 3)->next->next->val << endl;
    // system("pause");
    return 0;
}

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. 
You should preserve the original relative order of the nodes in each of the two partitions. 
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
*/