#include <iostream>
using namespace std;
char radix[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main(void) {
    int N, i;
    cout << "#";
    for (i = 0; i < 3; i++) {
        cin >> N;
        cout << radix[N/13] << radix[N%13];
    }
    cout << endl;
    return 0;
}

