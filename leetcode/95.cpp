#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        int left = 0, right = n;
        vector<TreeNode *> res;
        vector<vector<unordered_set<TreeNode *>>>(n, vector<unordered_set<TreeNode *>>(n, ;
    }
};

int main(void) {
    cout << Solution().generateTrees(3).size() << endl;
    // system("pause");
    return 0;
}
