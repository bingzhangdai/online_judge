#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    struct Trie {
        int val;
        // 1
        Trie* left = NULL;
        // 0
        Trie* right = NULL;
        Trie(int val) : val(val) {}
    };
    Trie *root = new Trie(0);
public:
    int findMaximumXOR(vector<int>& nums) {
        for (auto num : nums) {
            auto curr = root;
            for (int j = 30; j >= 0; j--) {
                if ((1 << j) & num) {
                    if (!curr->left)
                        curr->left = new Trie(1);
                    curr = curr->left;
                } else {
                    if (!curr->right)
                        curr->right = new Trie(0);
                    curr = curr->right;
                }
            }
            curr->val = num;
        }
        int res = 0;
        for (auto num : nums) {
            auto curr = root;
            for (int j = 30; j >= 0; j--) {
                if (!curr->left)
                    curr = curr->right;
                else if (!curr->right)
                    curr = curr->left;
                else {
                    if ((1 << j) & num)
                        curr = curr->right;
                    else
                        curr = curr->left;
                }
            }
            res = max(res, num ^ curr->val);
        }
        return res;
    }
};

int main(void) {
    return 0;
}
