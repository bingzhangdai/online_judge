#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> seq;

int main(void) {
    int N, p, i, j, m, max;
    scanf("%d%d", &N, &p);
    for (i = 0; i < N; i ++) {
        scanf("%d", &m);
        seq.push_back(m);
    }
    sort(seq.begin(), seq.end());
    for (j = N-1; j >= 0; j--)
        if (((double)seq[j])/p <= seq[0])
            break;
    max = j + 1;
    for (i = 0; i < N; i++) {
        while (j < N && ((double)seq[j])/p <= seq[i])
            j++;
        if (j - i > max)
            max = j - i;
        if (j == N)
            break;
    }
    printf("%d\n", max);
        
    return 0;
}

