#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime(int n) {
    bool flag = true;
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) {
            flag = false;
            break;
        }
    return flag;
}

int Reverse(int n, int radix) {
    int sum = 0;
    while (n) {
        sum = (n % radix) + sum * radix;
        n /= radix;
    }
    return sum;
}

int main(void) {
    int N, D;
    for(cin >> N; N >= 0; cin >> N) {
        cin >> D;
        if (IsPrime(N) && IsPrime(Reverse(N, D)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

