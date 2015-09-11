#include <iostream>
#include <deque>
using namespace std;

deque<int> stack;
deque<int> porder;
int tree[30][2]; // 0 left, 1 right;
int root;

void postorder(int root) {
    if (tree[root][0])
        postorder(tree[root][0]);
    if (tree[root][1])
        postorder(tree[root][1]);
    porder.push_back(root);
}


int main(void) {
    int N, m, lastm, npush(1), npop(0);
    string op, lastop;
    cin >> N >> op >> root;
    stack.push_back(root);
    lastm = root;
    lastop = op;
    while (npush != N || npop !=N) {
        cin >> op;
        if (op == "Push") {
            cin >> m;
            stack.push_back(m);
            if (lastop == "Push")
                tree[lastm][0] = m;
            else
                tree[lastm][1] = m;
            npush++;
        } else {
            m = stack[stack.size() -1];
            stack.pop_back();
            npop++;
        }
        lastop = op;
        lastm = m;
    }
    postorder(root);
    cout << porder[0];
    for (int i = 1; i < porder.size(); i++)
        cout << " " << porder[i];
    cout << endl;
    return 0;
}

