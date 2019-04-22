#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        int steps = 0;
        while (n != 1 && n % 2 == 0) {
             n /= 2;
             steps++;
        }
        if (n == 1)
            return steps;
        return steps + min(integerReplacement(((long long)n + 1) / 2) + 1, integerReplacement(n - 1)) + 1;
    }
};

int main(void) {
    return 0;
}
