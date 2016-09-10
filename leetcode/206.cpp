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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        while (head) {
            auto next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

int main(void) {
    return 0;
}
