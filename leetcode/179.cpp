#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    struct {
        bool operator()(const string& m, const string& n) {
            int i = 0, j = 0;
            int m_n_end = 0;
            while (m_n_end < 2) {
                if (m[i] != n[j])
                    return m[i] > n[j];
                if (++i == m.size()) {
                    i %= m.size();
                    m_n_end++;
                }
                if (++j == n.size()) {
                    j %= n.size();
                    m_n_end++;
                }
            }
            return false;
        }
    } cmp;
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_str;
        for (const auto n : nums)
            num_str.push_back(to_string(n));
        sort(num_str.begin(), num_str.end(), cmp);
        string res = "";
        for (const auto& s : num_str)
            res += s;
        return res;
    }
};
int main(void) {
    return 0;
}
