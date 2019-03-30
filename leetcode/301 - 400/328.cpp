#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return head;
        ListNode *odd_head = head, *even_head = head->next,
            *odd_curr = head, *even_curr = head->next,
            *current = head->next;
        bool odd = true;
        while (current && current->next) {
            if (odd)
                current = odd_curr = odd_curr->next = current->next;
            else
                current = even_curr = even_curr->next = current->next;
            odd = !odd;
        }
        if (odd)
            odd_curr->next = NULL;
        else
            even_curr->next = NULL;
        odd_curr->next = even_head;
        return odd_head;
    }
};

int main(void) {
    return 0;
}
