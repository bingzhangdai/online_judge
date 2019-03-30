#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto res = vector<string>();
        int i(0), j(0), len;
        while (i < words.size()) {
            len = words[i].length();
            for (j = i + 1; j < words.size(); j++) {
                len += 1 + words[j].length();
                if (len > maxWidth)
                    break;
            }
            if (j == words.size())
                break;
            len -= (1 + words[j].length());
            string s = "";
            for (int k = i; k < j; k++) {
                s += words[k];
                int padding = -1;
                if (k != j - 1)
                    padding = ceil((float)(maxWidth - len) / (j - k - 1));
                if (j - i == 1)
                    padding = maxWidth - len - 1;
                s.insert(s.size(), padding + 1, ' ');
                len += padding;
            }
            res.push_back(s);
            i = j;
        }
        string s = words[i];
        while (++i < j) {
            s += " " + words[i];
        }
        s.insert(s.length(), maxWidth - len, ' ');
        res.push_back(s);
        return res;
    }
};

int main(void) {
    vector<string> words = {"Listen","to","many,","speak","to","a","few."};
    auto res = Solution().fullJustify(words, 6);
    for_each(res.begin(), res.end(), [](const auto& s) { cout << s.length() << endl; });
    // system("pause");
    return 0;
}
