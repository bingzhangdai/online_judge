#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *remove_node_after(ListNode *node) {
        auto next = node->next;
        node->next = next->next;
        return next;
    }
    inline void insert_node_after(ListNode *node, ListNode *to_be_inserted) {
        to_be_inserted->next = node->next;
        node->next = to_be_inserted;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;
        for (auto i = head; i->next != nullptr;) {
            auto node = remove_node_after(i);
            if (head->val > node->val) {
                node->next = head;
                head = node;
            }
            else {
                ListNode *target = head;
                while (target->next && target->next->val < node->val && target != i)
                    target = target->next;
                insert_node_after(target, node);
                if (target == i)
                    i = i->next;
            }
        }
        return head;
    }
};

int main(void) {
    auto head = new ListNode(5);
    head->next = new ListNode(0);
    Solution().insertionSortList(head);
    return 0;
}
