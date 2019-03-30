#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
Example 1:
Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:
Input: "1,#"
Output: false
Example 3:
Input: "9,#,#,1"
Output: false
*/

#define NULL_PTR '#'
#define VALID_PTR '*'

class Solution {
    deque<char> preorder_list;
    void split(const string& preorder) {
        for (int i = 0; i < preorder.length();) {
            if (preorder[i] == NULL_PTR)
                preorder_list.push_back(NULL_PTR);
            else
                preorder_list.push_back(VALID_PTR);
            i = preorder.find(',', i) + 1;
            if (i == 0) i = preorder.length();
        }
    }
public:
    bool isValidSerialization(string preorder) {
        split(preorder);
        while (true) {
            bool found = false;
            for (auto it = preorder_list.begin() + 1; it < preorder_list.end() - 1; ++it) {
                if (*it == NULL_PTR && *(it + 1) == NULL_PTR && *(it - 1) != NULL_PTR) {
                    *(it - 1) = NULL_PTR;
                    it = preorder_list.erase(it);
                    preorder_list.erase(it);
                    found = true;
                    break;
                }
            }
            if (!found)
                break;
        }
        return preorder_list.size() == 1 && preorder_list[0] == NULL_PTR;;
    }
};

int main(void) {
    return 0;
}
