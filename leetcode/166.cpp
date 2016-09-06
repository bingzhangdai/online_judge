#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    string frac_tostr(long num, long den) {
        unordered_map<long, int> hash_map;
        string res = num ? "." : "";
        while (num) {
            auto p = hash_map.find(num);
            if (p != hash_map.end()) {
                res.insert((*p).second, 1, '(');
                return res + ")";
            }
            else
                hash_map[num] = res.size();
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }
        return res;
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign = numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0;
        long num = abs((long)numerator), den = abs((long)denominator);
        return (sign ? "-" : "") + to_string(num / den) + frac_tostr(num % den, den);
    }
};

int main(void) {
    cout << Solution().fractionToDecimal(1, 9) << endl;
    return 0;
}
