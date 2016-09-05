#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
    int gcd(int m, int n) {
        while (m % n) {
            auto tmp = n;
            n = m % n;
            m = tmp;
        }
        return n;
    }
    string frac_tostr(int numerator, int denominator) {
        int n = numerator;
        string res = "";
        do {
            n *= 10;
            res += itos(n / denominator);
            n %= denominator;
        }
        while (n != numerator && n != 0);
        return n ? "(" + res + ")" : res;
    }
    inline string itos(int num) {
        return string(itoa(num));
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        int gcdivisor = gcd(numerator, denominator);
        numerator /= gcdivisor;
        denominator /= gcdivisor;
        return itos(numerator / denominator) + (numerator % denominator ? "." + frac_tostr(numerator, denominator) : "");
    }
};

int main(void) {
    return 0;
}
