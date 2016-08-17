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
        vector<TreeNode *> res;
        if (n == 0)
            return res;
        vector<vector<unordered_set<TreeNode *>>> dp(n, vector<unordered_set<TreeNode *>>(n, unordered_set<TreeNode *>()));
        for (int j = 0; j < n; j++)
            dp[0][j].insert(new TreeNode(j + 1));
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                for (int k = j; k < i + j + 1; k++) {
                    if (k - j == 0) {
                        for (const auto& node : dp[i-1][k+1]) {
                            auto root = new TreeNode(k + 1);
                            root->right = node;
                            dp[i][j].insert(root);
                        }
                    }
                    else if (k - i - j == 0) {
                        for (const auto& node : dp[i-1][j]) {
                            auto root = new TreeNode(k + 1);
                            root->left = node;
                            dp[i][j].insert(root);
                        }
                    }
                    else {
                        for (const auto& left : dp[k-j-1][j]) {
                            for (const auto& right : dp[i+j-k-1][k+1]) {
                                auto root = new TreeNode(k + 1);
                                root->left = left;
                                root->right = right;
                                dp[i][j].insert(root);
                            }
                        }
                    }
                }
            }
        }
        for (const auto& node : dp[n-1][0])
            res.push_back(node);
        return res;
    }
};

int main(void) {
    cout << Solution().generateTrees(3).size() << endl;
    // system("pause");
    return 0;
}
