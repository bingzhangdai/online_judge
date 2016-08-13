#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *head, *ptr;
        if (l1->val < l2->val) {
            ptr = head = l1;
            l1 = l1->next;
        }
        else {
            ptr = head = l2;
            l2 = l2->next;
        }
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;
            }
            else {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        ptr->next = (l1 == nullptr) ? l2 : l1;
        return head;
    }
};

int main(void) {
    cout << Solution().mergeTwoLists(new ListNode(2), new ListNode(1))->next->val << endl;

    system("pause");
    return 0;
}
