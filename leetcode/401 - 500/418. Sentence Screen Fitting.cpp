#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size(), num = 0;
        vector<int> mp(n, 0);
        while (rows--) {
            auto i = num % n;
            if (!mp[i]) {
                int j = i - 1, count = 0, len = -1;
                while (j = (j + 1) % n, (len += 1 + sentence[j].length()) <= cols) {
                    count++;
                }
                mp[i] = count;
            }
            num += mp[i];
        }
        return num / n;
    }
};

class Solution_LTE {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        for (const auto& word : sentence)
            if (word.length() > cols)
                return 0;
        int i = 0, j = 0, count = 0;
        while (i < rows) {
            for (int ind = 0; ind < sentence.size(); ind++) {
                if (i >= rows)
                    return count;
                j += sentence[ind].length() + 1;
                if (j + sentence[(ind + 1) % sentence.size()].length() > cols)
                    i++, j = 0;
            }
            count++;
            if (j == 0) {
                auto repeat = rows / i;
                i *= repeat;
                count *= repeat;
            }
        }
        return count;
    }
};

int main(void) {
    return 0;
}
