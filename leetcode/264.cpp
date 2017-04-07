#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
    const int TWO_MAX = INT_MAX / 2;
    const int THREE_MAX = INT_MAX / 3;
    const int FIVE_MAX = INT_MAX / 5;
public:
    int nthUglyNumber(int n) {
        set<int> ugly;
        ugly.insert(1);
        while (--n) {
            int num = *ugly.begin();
            ugly.erase(ugly.begin());
            /*
            if (ugly.size() > n && num * 2 > *(--ugly.end()))
                break;
            */
            if (num <= TWO_MAX)
                ugly.insert(num * 2);
            if (num <= THREE_MAX)
                ugly.insert(num * 3);
            if (num <= FIVE_MAX)
                ugly.insert(num * 5);

        }
        auto it = ugly.begin();
        /*
        while (n > 0 && --n)
            ++it;
        */
        return *it;
    }
};

int main(void) {
    Solution().nthUglyNumber(7);
    return 0;
}
