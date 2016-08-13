#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
    }
};


int main(void) {
    vector<vector<int>> matrix {{1,   3,  5,  7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50};
    cout << Solution().searchMatrix(matrix, 3) << endl;
    // system("pause");
    return 0;
}
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
*/