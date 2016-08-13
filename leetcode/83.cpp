#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *ptr = head;
        while (ptr->next != nullptr) {
            if (ptr->val == ptr->next->val) {
                auto next = ptr->next;
                ptr->next = next->next;
                delete next;
            }
            else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};

int main(void) {
    auto a = new ListNode(3);
    a->next = new ListNode(3);
    cout << Solution().deleteDuplicates(a)->next << endl;
    // system("pause");
    return 0;
}
/*
Given a sorted linked list, delete all duplicates such that each element appear only once. 
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 
*/
