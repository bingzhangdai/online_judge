#include <iostream>
#include <deque>
using namespace std;
int N, postorder[30], inorder[30];
deque<int> levelorder;
struct node {
    int n;
    struct node *left;
    struct node *right;
};
struct node *buildtree(int l, int r) {
    struct node *root = new struct node;
    root->left = root->right = NULL;
    root->n = postorder[r];
    int i;
    for (i = l; i < r; i++)
        if (inorder[i] == postorder[r])
            break;
    if (l != i)
        root->left = buildtree(l, i-1);
    if (r != i) {
        for (int j = r; j > i; j--)
            postorder[j] = postorder[j-1]; // 搬运工, lol
        root->right = buildtree(i+1, r);
    }
    return root;
}

void bfs(struct node *root) {
    deque<struct node *> que;
    que.push_back(root);
    while (que.size()) {
        root = que[0];
        que.pop_front();
        levelorder.push_back(root->n);
        if(root->left)
            que.push_back(root->left);
        if(root->right)
            que.push_back(root->right);
    }
}

int main(void) {
    int i, l, r;
    struct node *root = NULL;
    cin >>N;
    for (i = 0; i < N; i++)
        cin >> postorder[i];
    for (i = 0; i < N; i++)
        cin >>inorder[i];
    root = buildtree(0, N-1);
    bfs(root);
    for (i = 0; i < N-1; i++)
        cout << levelorder[i] << " ";
    cout << levelorder[i] << endl;
    return 0;
}

