#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto countA = 0, countB = 0;
        auto ptrA = headA, ptrB = headB;
        if (!headA || !headB)
            return nullptr;
        while (ptrA->next) {
            ptrA = ptrA->next;
            countA++;
        }
        while (ptrB->next) {
            ptrB = ptrB->next;
            countB++;
        }
        if (ptrA != ptrB)
            return nullptr;
        while (countA > countB) {
            headA = headA->next;
            countA--;
        }
        while (countA < countB) {
            headB = headB->next;
            countB--;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main(void) {
    return 0;
}
