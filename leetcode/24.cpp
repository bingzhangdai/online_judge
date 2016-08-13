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
    /*
    ListNode* swapPairs(ListNode* head) {
        ListNode *p0, *p1, *p2 = head;
        if (head == nullptr)
            return head;
        if (p2->next == nullptr)
            return p2;
        p1 = p2;
        p2 = p2->next;
        if (p2->next == nullptr) {
            p2->next = p1;
            p1->next = nullptr;
            return p2;
        }
        p0 = p1;
        p1 = p1->next;
        p2 = p2->next;
        p0->next = nullptr;
        do {
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            p2 = p2->next;
        } while (p2 != nullptr);
        p1->next = p0;
        return p1;
    }
    */
    ListNode* swapPairs(ListNode* head) {
        // 0 node
        if (head == nullptr)
            return head;
        ListNode *p0, *p1 = head;
        // only one node
        if (p1->next == nullptr)
            return p1;
        p1 = p1->next;
        ListNode *pseudohead = new ListNode(0);
        pseudohead->next = head;
        p0 = pseudohead;
        while (true) {
            p0->next->next = p1->next;
            p1->next = p0->next;
            p0->next = p1;
            p0 = p1->next;
            p1 = p0->next;
            if (p1 == nullptr || p1->next == nullptr)
                break;
            p1 = p1->next;
        }
        p0 = pseudohead->next;
        delete pseudohead;
        return p0;
    }

};

int main(void) {
    cout << Solution().swapPairs(new ListNode(0))->val << endl;

    system("pause");
    return 0;
}
