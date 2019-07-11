#include <iostream>
#include <vector>
#include <string>
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
        vector<int> count('9' - '0' + 1, 0);
        auto bull = 0, cow = 0;
        for (auto i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bull++;
            else
                count[secret[i] - '0']++;
        }
        for (auto i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && count[guess[i] - '0'])
                count[guess[i] - '0']--, cow++;
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};

int main(void) {
    return 0;
}
