#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto pseudo_head = new ListNode(-1);
        pseudo_head->next = head;
        for (head = pseudo_head; head->next;) {
            auto tmp = head->next;
            if (head->next->val == val) {
                head->next = tmp->next;
                delete tmp;
            }
            else
                head = tmp;
        }
        head = pseudo_head->next;
        delete pseudo_head;
        return head;
    }
};
int main(void) {
    return 0;
}
