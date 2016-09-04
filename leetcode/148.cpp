#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *find_mid(ListNode *left, ListNode *right) {
        auto fast = left, slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *head, *ptr;
        if (left->val < right->val) {
            head = ptr = left;
            left = left->next;
        }
        else {
            head = ptr = right;
            right = right->next;
        }
        while (left && right) {
            if (left->val < right->val) {
                ptr->next = left;
                left = left->next;
            }
            else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        if (left)
            ptr->next = left;
        else
            ptr->next = right;
        return head;
    }
    ListNode *merge_sort(ListNode *left, ListNode* right) {
        if (left->next == right) {
            left->next = nullptr;
            return left;
        }
        auto mid = find_mid(left, right);
        auto left_part = merge_sort(left, mid);
        auto right_part = merge_sort(mid, right);
        return merge(left_part, right_part);
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        return merge_sort(head, nullptr);
    }
};

int main(void) {
    auto head = new ListNode(5);
    head->next = new ListNode(0);
    Solution().sortList(head);
    return 0;
}
