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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 && !list2) {
            return NULL;
        }
        ListNode *head, *current;
        auto min_head = !list1 ? &list2 : !list2 ? &list1 : list1->val < list2->val ? &list1 : &list2;
        head = current = *min_head;
        *min_head = (*min_head)->next;
        current->next = NULL;
        while (list1 || list2) {
            min_head = !list1 ? &list2 : !list2 ? &list1 : list1->val < list2->val ? &list1 : &list2;
            current->next = *min_head;
            *min_head = (*min_head)->next;
            current = current->next;
        }
        return head;
    }
};

int main(void) {
    cout << Solution().mergeTwoLists(new ListNode(2), new ListNode(1))->next->val << endl;

    system("pause");
    return 0;
}
