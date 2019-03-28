#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (auto i : citations)
            count[i >= n ? n : i]++;
        int num = 0;
        for (int i = n; i >=0; i--) {
            if ((num + count[i]) >= i && num <= i)
                return i;
            num += count[i];
        }
        return 0;
    }
};

int main(void) {
    return 0;
}
