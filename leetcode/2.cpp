#include <cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *pos;
        int sum(l1->val + l2->val);
        result = new ListNode(sum % 10);
        pos = result;
        sum /= 10;
        while (l1->next != NULL || l2->next != NULL) {
            if (l1->next != NULL) {
                l1 = l1->next;
                sum += l1->val;
            }
            if (l2->next != NULL) {
                l2 = l2->next;
                sum += l2->val;
            }
            pos->next = new ListNode(sum % 10);
            pos = pos->next;
            sum /= 10;
        }
        if (sum) {
            pos->next = new ListNode(sum);
            pos = pos->next;
        }
        pos->next = NULL;
        return result;
    }
};
