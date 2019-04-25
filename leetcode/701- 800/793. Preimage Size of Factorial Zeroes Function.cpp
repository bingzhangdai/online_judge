#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int num_of_zero(long long X) {
        int res = 0;
        while (X != 0) {
            res += X /= 5;
        }
        return res;
    }
public:
    int preimageSizeFZF(int K) {
        long long left = 0, right = 5L * (K + 1);
        while (left < right) {
            auto mid = (left + right) / 2;
            auto res = num_of_zero(mid);
            if (res < K)
                left = mid + 1;
            else if (res > K)
                right = mid - 1;
            else
                return 5;
        }
        return 0;
    }
};

class Solution_LTE {
public:
    int preimageSizeFZF(int K) {
        int num_of_zero = 0, curr = 1;
        while (num_of_zero < K) {
            int tmp = curr + 4;
            int count = 0;
            while (tmp % 5 == 0) {
                tmp /= 5;
                count++;
            }
            if (num_of_zero + count == K) {
                return 5;
            }
            else if (num_of_zero + count > K)
                return 0;
            num_of_zero += count;
            curr += 5;
       }
       return 5;
    }
};

int main(void) {
    return 0;
}
