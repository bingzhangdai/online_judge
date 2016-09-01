#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int max_sum = -1, max_sum_start = -1, start = 0, sum = 0, n = gas.size(), total_sum = 0;
        for (int i = 0; i < n * 2; i++) {
            sum += gas[i%n] - cost[i%n];
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
            if (sum > max_sum) {
                max_sum = sum;
                max_sum_start = start;
            }
        }
        for (int i = 0; i < n; i++)
            total_sum += gas[i%n] - cost[i%n];
        return total_sum < 0 ? -1 : max_sum_start;
    }
};

int main(void) {
    return 0;
}