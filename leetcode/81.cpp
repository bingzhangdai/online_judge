#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
    }
};


int main(void) {
    vector<vector<int>> matrix {{1,   3,  5,  7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50};
    cout << Solution().searchMatrix(matrix, 3) << endl;
    // system("pause");
    return 0;
}
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*.