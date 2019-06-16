#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, pos_b = 0, a = -1, b = -1;
        int start = 0, end = 0;
        while (end < tree.size()) {
            if (a == -1) {
                if (tree[end] != b)
                    a = b, b = tree[end], pos_b = end;
            }
            else if (tree[end] != a && tree[end] != b) {
                break;
            }
            else if (tree[end] == a) {
                a = b, b = tree[end], pos_b = end;
            }
            res++, end++;
        }
        while (end < tree.size()) {
            if (tree[end] == a) {
                pos_b = end;
                swap(a, b);
            }
            if (tree[end] != b) {
                start = pos_b;
                pos_b = end;
                a = b;
                b = tree[end];
            }
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
