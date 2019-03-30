#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *NodeAtK(ListNode *head, int k) {
        while (--k && head) {
            head = head->next;
        }
        return head;
    }
    ListNode *reverse(ListNode *head, int k) {
        ListNode *pre = nullptr, *curr = head;
        while (k-- && curr) {
            auto _next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = _next;
        }
        return pre;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 0 || k == 1)
            return head;
        auto pre = &head;
        auto curr = head;
        auto _next = NodeAtK(head, k);
        while (curr && _next) {
            auto tmp = _next->next;
            *pre = reverse(curr, k);
            curr->next = tmp;
            pre = &curr->next;
            curr = tmp;
            _next = NodeAtK(curr, k);
        }
        return head;
    }
};

int main(void) {
    cout << Solution().reverseKGroup(new ListNode(0), 1)->val << endl;
    return 0;
}
