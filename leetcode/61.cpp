#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *left(head), *right(head);
        if (head == NULL)
            return head;
        int count = 0;
        for (ListNode *ptr = head; ptr; ptr = ptr->next)
            count++;
        k %= count;
        while (k--)
            right = right->next;
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        right->next = head;
        head = left->next;
        left->next = NULL;
        return head;
    }
};

int main(void) {
    auto head = new ListNode(4);
    cout << Solution().rotateRight(head, 0)->val << endl;
    // system("pause");
    return 0;
}
