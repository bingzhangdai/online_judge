#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int num_of_nums = 9, num_of_digit = 1;
        while (true) {
            long long tmp = (long long)num_of_digit * num_of_nums;
            if ((long long)n - tmp > 0) {
                n -= num_of_digit * num_of_nums;
                num_of_digit++;
                num_of_nums *= 10;
            }
            else
                break;
        }
        int num = num_of_nums / 9 + (n - 1) / num_of_digit;
        int digit = (num_of_digit - 1) - (n - 1) % num_of_digit;
        for (int i = 0; i < digit; i++)
            num /= 10;
        return num % 10;
    }
};

int main(void) {
    return 0;
}
