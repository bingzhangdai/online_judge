#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
Example 1:
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation: 
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.

Example 2:
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation: 
The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.

Note:
There are at most 6 kinds of items, 100 special offers.
For each item, you need to buy at most 6 of them.
You are not allowed to buy more items than you want, even if that would lower the overall price.
*/

class Solution {
    int res = INT_MAX;
    void buy(vector<int>& needs, const vector<int>& offer) {
        for (int i = 0; i < needs.size(); i++)
            needs[i] -= offer[i];
    }
    void noBuy(vector<int>& needs, const vector<int>& offer) {
        for (int i = 0; i < needs.size(); i++)
            needs[i] += offer[i];
    }
    bool can(const vector<int>& needs, const vector<int>& offer) {
        for (int i = 0; i < needs.size(); i++)
            if (needs[i] < offer[i])
                return false;
        return true;
    }
    bool finished(const vector<int>& needs) {
        for (auto need : needs)
            if (need != 0)
                return false;
        return true;
    }
    void dfs(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs, int cost) {
        if (finished(needs)) {
            res = min(res, cost);
            return;
        }
        // buy individual items
        int curr = cost;
        for (int i = 0; i < needs.size(); i++)
            curr += needs[i] * price[i];
        res = min(curr, res);
        // buy a special offer
        for (const auto& offer : special) {
            if (can(needs, offer)) {
                buy(needs, offer);
                dfs(price, special, needs, cost + offer.back());
                noBuy(needs, offer);
            }
        }
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        dfs(price, special, needs, 0);
        return res;
    }
};

int main(void) {
    return 0;
}
