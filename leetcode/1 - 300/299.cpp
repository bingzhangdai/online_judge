#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Example 1:
Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:
Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count_guess (10, 0);
        vector<int> count_secret(10, 0);
        int m = secret.length(), n = guess.length(), A = 0, B = 0;
        int min_len = min(m, n);
        for (int i = 0; i < min_len; i++) {
            if (secret[m - i - 1] == guess[n - i - 1])
                A++;
            else {
                count_secret[secret[m - i - 1] - '0']++;
                count_guess[guess[n - i - 1] - '0']++;
            }
        }
        for (int i = min_len; i < m; i++)
            count_secret[secret[m - i - 1] - '0']++;
        for (int i = min_len; i < n; i++)
            count_guess[guess[n - i - 1] - '0']++;
        for (int i = 0; i < 10; i++) {
            B += min(count_guess[i], count_secret[i]);
        }
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};

int main(void) {
    return 0;
}
