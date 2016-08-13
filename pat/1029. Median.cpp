#include <stdio.h>
using namespace std;
const int Max = 1000000;
long int seq[2][Max+1];

long int findmedian(int median) {
    int i(0), j(0);
    for (;;) {
        if (i == seq[0][Max]) {
            j++;
            if (--median == 0) {
                return seq[1][j-1];
            }
        }
        else if (j == seq[1][Max]) {
            i++;
            if (--median == 0) {
                return seq[0][i-1];
            }
        }
        else {
            if (seq[0][i] > seq[1][j]) {
                j++;
                if (--median == 0)
                    return seq[1][j-1];
            }
            else {
                i++;
                if (--median == 0)
                    return seq[0][i-1];
            }
        }
    }
}
int main(void) {
    int sum(0), i, j;

    for (i = 0; i < 2; i++) {
        scanf("%ld", &seq[i][Max]);
        sum += seq[i][Max];
        for (j = 0; j < seq[i][Max]; j++)
            scanf("%ld", &seq[i][j]);
    }
    if ((seq[0][Max] + seq[1][Max]) %2)
        printf("%ld\n", findmedian(sum / 2 + 1));
    else
        printf("%ld\n", findmedian(sum / 2));
    return 0;
}

