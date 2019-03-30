#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
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
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
    }
};

int main(void) {
    cout << Solution().mergeKLists(vector<ListNode *>({ new ListNode(2), new ListNode(0) }))->val << endl;

    system("pause");
    return 0;
}
