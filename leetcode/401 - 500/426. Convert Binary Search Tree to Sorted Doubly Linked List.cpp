#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node *head = NULL, *tail = NULL;
    void inOrder(Node *root) {
        if (!root)
            return;
        inOrder(root->left);
        root->left = tail;
        if (tail)
            tail->right = root;
        tail = root;
        if (!head)
            head = root;
        inOrder(root->right);
    }
public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return root;
        inOrder(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
};

int main(void) {
    return 0;
}
