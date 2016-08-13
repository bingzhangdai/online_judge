#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* next_k_minus_1(ListNode* head, int k) {
        while (--k) {
            if (head == nullptr)
                break;
            head = head->next;
        }
        return head;
    }
    // return the head of reversed list (reverse k nodes)
    ListNode* reverse(ListNode* head, int k) {
        ListNode *p0, *p1(head), *p2(head->next);
        ListNode *tail = next_k_minus_1(head, k)->next;
        if (k == 2) {
            p2->next = p1;
            p1->next = tail;
            return p2;
        }
        p0 = p1;
        p1 = p1->next;
        p2 = p2->next;
        p0->next = tail;
        do {
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            p2 = p2->next;
        } while (--k > 2);
        p1->next = p0;
        return p1;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1)
            return head;
        ListNode* h = head;
        if (next_k_minus_1(head, k) == nullptr)
            return head;
        head = h = reverse(head, k);
        while (true) {
            head = next_k_minus_1(head, k);
            if (next_k_minus_1(head->next, k) == nullptr)
                break;
            head->next = reverse(head->next, k);
            head = head->next;
        }
        return h;
    }
};

int main(void) {
    cout << Solution().reverseKGroup(new ListNode(0), 1)->val << endl;

    system("pause");
    return 0;
}
