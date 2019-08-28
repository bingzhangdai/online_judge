#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Use ListNode ** to avoid to new ListNode;
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        auto p_next = &head;
        while ((--n, --m) && *p_next)
            p_next = &(*p_next)->next;
        ListNode *tail = *p_next, *prev = *p_next;
        if (!prev)
            return head;
        auto curr = prev->next;
        while (curr && n--) {
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        *p_next = prev;
        tail->next = curr;
        return head;
    }
};

class Solution_OLD {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *p1 = new ListNode(-1), *p2, *p3, *p4, *p5, *p6;
        p1->next = head;
        head = p1;
        int count = 0;
        while (++count < m)
            p1 = p1->next;
        
        p2 = p3 = p1->next;
        if (n - m >= 1) {
            p4 = p3->next;
            p5 = p4->next;
            p4->next = p3;
            while (count++ <= n - 2) {
                p3 = p4;
                p4 = p5;
                p5 = p5->next;
                p4->next = p3;
            }
            p1->next = p4;
            p2->next = p5;
        }
        p6 = head->next;
        delete head;
        return p6;
    }
};

int main(void) {
    cout << Solution().reverseBetween(nullptr, 2, 4) << endl;
    // system("pause");
    return 0;
}
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass. 
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4, 
return 1->4->3->2->5->NULL. 
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
*/