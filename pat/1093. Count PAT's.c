#include <stdio.h>

int main(void) {
    char patstr[100001];
    long long int p, pa, pat;
    int i;
    p = pa = pat = 0;
    scanf("%s", patstr);
    for (i = 0; patstr[i] != '\0'; i++)
        if (patstr[i] == 'P')
            p++;
        else if (patstr[i] == 'A')
            pa += p;
        else if (patstr[i] == 'T')
            pat += pa;
    printf("%lld\n", pat % 1000000007);
    return 0;
}

