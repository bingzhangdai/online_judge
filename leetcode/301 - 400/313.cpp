#include <iostream>
#include <climits>
#include <queue>
using namespace std;

/*
Example:
Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int current = 0;
        heap.push(1);
        while (n--) {
            current = heap.top();
            while (heap.size() && heap.top() == current)
                heap.pop();
            for (auto prime : primes) {
                long tmp = (long) current * prime;
                if (tmp > INT_MAX)
                    continue;
                heap.push(tmp);
            }
        }
        return current;
    }
};

int main(void) {
    return 0;
}
