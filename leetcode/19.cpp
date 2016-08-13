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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1(head), *p2(head);
        while (n--) {
            p2 = p2->next;
        }
        // remove the head node
        if (p2 == nullptr) {
            ListNode *p = p1->next;
            delete p1;
            return p;
        }
        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *p = p1->next;
        p1->next = p->next;
        delete p;
        return head;
    }
};

int main(void) {
    cout << Solution().removeNthFromEnd((ListNode *)malloc(sizeof(ListNode)), 0)->val << endl;

    system("pause");
    return 0;
}
