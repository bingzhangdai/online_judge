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
    ListNode* swapPairs(ListNode *head) {
        auto pre = &head;
        auto curr = head;
        while (curr && curr->next) {
            auto _next = curr->next;
            auto tmp = _next->next;
            *pre = _next;
            _next->next = curr;
            curr->next = tmp;
            pre = &curr->next;
            curr = tmp;
        }
        return head;
    }
};

int main(void) {
    cout << Solution().swapPairs(new ListNode(0))->val << endl;
    return 0;
}
