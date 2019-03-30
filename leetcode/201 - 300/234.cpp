#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!slow)
            return true;
        fast = slow->next;
        slow->next = nullptr;
        while (fast) {
            auto tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        while (slow) {
            if (slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};

int main(void) {
    return 0;
}
