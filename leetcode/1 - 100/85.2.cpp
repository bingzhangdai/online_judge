#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Example:
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
    }
};

int main(void) {
    vector<vector<char>> matrix {{'1','0','1','0','0'},
                                 {'1','0','1','1','1'},
                                 {'1','1','1','1','1'},
                                 {'1','0','0','1','0'}};
    cout << Solution().maximalRectangle(matrix) << endl;
    // system("pause");
    return 0;
}

