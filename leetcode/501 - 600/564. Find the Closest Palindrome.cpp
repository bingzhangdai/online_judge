#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool isPalindrome(const string& n) {
        int i = 0, j = n.length() - 1;
        while (i < j) {
            if (n[i++] != n[j--])
                return false;
        }
        return true;
    }
    string toPalindrome(long long num) {
        string tmp = to_string(num);
        int n = tmp.length();
        for (int i = 0; i < n / 2; i++) {
            tmp[n - i - 1] = tmp[i];
        }
        return tmp;
    }
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        // Corner cases
        // 999
        bool all_nine = true;
        for (auto c : n)
            if (c != all_nine) {
                all_nine = false;
                break;
            }
        if (all_nine)
            return to_string(num + 2);
        // 10
        if (num <= 10 || n[0] == '1' && stoll(n.substr(1, n.length() - 1)) == 0)
            return to_string(num - 1);
        // 11, 101
        if (n[0] == '1' && n[n.length() - 1] == '1' && (n.length() == 2 || stoll(n.substr(1, n.length() - 2)) == 0))
            return to_string(num - 2);
        long long half = 1;
        for (int i = 0; i < n.length() / 2; i++) {
            half *= 10;
        }
        string res = toPalindrome(num + half);
        long long diff = abs(stoll(res) - num);
        if (!isPalindrome(n)) {
            string candidate = toPalindrome(num);
            long long diff_tmp = abs(stoll(candidate) - num);
            if (diff_tmp <= diff) {
                diff = diff_tmp;
                res = candidate;
            }
        }
        string candidate1 = toPalindrome(num - half);
        long long diff_tmp1 = abs(stoll(candidate1) - num);
        if (diff_tmp1 <= diff) {
            diff = diff_tmp1;
            res = candidate1;
        }
        return res;
    }
};

int main(void) {
    return 0;
}
