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
        ListNode *left, *right = head;
        // tmp head
        head = new ListNode(-1);
        head->next = right;
        left = head;
        while (right != nullptr) {
            auto next = right->next;
            if (next != nullptr && next->val == right->val) {
                auto val = right->val;
                while (right != nullptr && right->val == val) {
                    next = right->next;
                    delete right;
                    right = next;
                }
                left->next = right;
            }
            else {
                left = right;
                right = next;
            }
        }
        left = head;
        head = head->next;
        delete left;
        return head;
    }
};


int main(void) {
    cout << Solution().deleteDuplicates(nullptr) << endl;
    // system("pause");
    return 0;
}
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
*/