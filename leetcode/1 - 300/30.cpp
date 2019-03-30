#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        auto res = vector<int>();
        //auto wds{ unordered_map<string, int>() }, curwds{ unordered_map<string, int>() };
        auto wds = unordered_map<string, int>(), curwds = unordered_map<string, int>();
        int step(words[0].length());
        for (auto str : words)
            wds[str]++;
        if (step > s.length())
            return res;
        for (int i = 0; i < step; i++) {
            int left(i), count(words.size());
            curwds.clear();
            for (int j = left; j <= s.length() - step; j += step) {
                auto str = s.substr(j, step);
                if (wds.count(str)) {
                    curwds[str]++;
                    if (curwds[str] <= wds[str])
                        count--;
                    else {
                        while (curwds[str] > wds[str]) {
                            auto tmp = s.substr(left, step);
                            if (str != tmp)
                                count++;
                            curwds[tmp]--;
                            left += step;
                        }
                    }
                    if (count == 0) {
                        res.push_back(left);
                        auto tmp = s.substr(left, step);
                        curwds[tmp]--;
                        count++;
                        left += step;
                    }
                }
                else {
                    left = step + j;
                    curwds.clear();
                    count = words.size();
                }
            }
        }
        return res;
    }
};

int main(void) {
    auto p = vector<string>({ "word","good","best","good" });
    cout << Solution().findSubstring("wordgoodgoodgoodbestword", p).size() << endl;
    system("pause");
    return 0;
}
