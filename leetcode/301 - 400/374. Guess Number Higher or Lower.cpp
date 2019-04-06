#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

#define LOWER -1
#define HIGHER 1
#define BINGO 0

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            switch (guess(mid)) {
                case BINGO:
                    return mid;
                case HIGHER:
                    left = mid + 1;
                    break;
                case LOWER:
                    right = mid - 1;
                    break;
            }
        }
        return -1;
    }
};

int main(void) {
    return 0;
}
