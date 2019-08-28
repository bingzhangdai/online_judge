#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    void inorder_s(TreeNode *root, string& buff) {
        if (!root)
            return buff.push_back(',');
        buff += to_string(root->val) + ',';
        inorder_s(root->left, buff);
        inorder_s(root->right, buff);
    }
    TreeNode *inorder_d(const string& buff, int& idx) {
        auto comma = buff.find(',', idx);
        auto val = buff.substr(idx, comma - idx);
        idx = comma + 1;
        if (val == "")
            return nullptr;
        auto res = new TreeNode(stoi(val));
        res->left = inorder_d(buff, idx);
        res->right = inorder_d(buff, idx);
        return res;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res = "";
        inorder_s(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int idx = 0;
        return inorder_d(data, idx);
    }
};

int main(void) {
    return 0;
}
