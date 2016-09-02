#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        auto fast = head->next->next, slow = head;
        while (fast && fast->next) {
            if (fast == slow || fast->next == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};

int main(void) {
    return 0;
}
