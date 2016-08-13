#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    int N, n, first, max(1), i, j;
    cin >> N;
    first = N;
    for (i = 2; i <= sqrt(N); i++) {
        n = N;
        for (j = i; j <= n; j++)
            if (n % j != 0)
                break;
            else
                n /= j;
        if ((j - i > max) || ((j - i == max) && (i < first))) {
            max = j - i;
            first = i;
        }
    }
    cout << max << endl;
    for (i = 0; i < max -1; i++)
        cout << first++ << "*";
    cout << first << endl;
}


        
