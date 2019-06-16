#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    unordered_map<int, string> numbers{
        {0, "Zero"},
        {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
        {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
        {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty",},
        {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"},
        {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
    };

    void numbers3ToWords(int num, vector<string>& res) {
        if (num / 100) {
            res.push_back(numbers[num / 100]);
            res.push_back(numbers[100]);
        }
        num %= 100;
        if (num >= 20) {
            res.push_back(numbers[num - (num % 10)]);
            if (num % 10)
                res.push_back(numbers[num % 10]);
        }
        else if (num > 0) {
            res.push_back(numbers[num]);
        }
    }

    string join(char sep, const vector<string>& strs) {
        string res = "";
        for (int i = 0; i < strs.size() - 1; i++) {
            res += strs[i];
            res += sep;
        }
        return res + strs.back();
    }

public:
    string numberToWords(int num) {
        vector<string> res;
        if (num == 0)
            return numbers[num];
        for (auto t : {1000000000, 1000000, 1000}) {
            if (num / t) {
                auto rem = num % t;
                numbers3ToWords(num / t, res);
                res.push_back(numbers[t]);
                num = rem;
            }
        }
        if (num)
            numbers3ToWords(num, res);
        return join(' ', res);
    }
};

int main(void) {
    cout << Solution().numberToWords(1234567891) << endl;
    return 0;
}
