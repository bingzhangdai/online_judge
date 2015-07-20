#include <stdio.h>
#include <stdlib.h>

struct poly{
    int exp;
    double coe;
};

int main(void) {
    int i, j;
    int k[3];
    struct poly *p[3];
    for (i = 0; i < 2; i++){
        scanf("%d", &k[i]);
        p[i] = (struct poly *)malloc(sizeof(struct poly) * k[i]);
        for (j = 0; j < k[i] ; j++)
            scanf("%d %lf", &p[i][j].exp, &p[i][j].coe);
    }
    k[2] = p[0][0].exp + p[1][0].exp + 1;
    p[2] = (struct poly *)malloc(sizeof(struct poly) * k[2]);
    for (i = 0; i < k[2]; i++)
        p[2][i].coe = 0;
    for (i = 0; i < k[0]; i++)
        for (j = 0; j < k[1]; j++)
            p[2][p[0][i].exp + p[1][j].exp].coe += p[0][i].coe * p[1][j].coe;
    j = 0;
    for (i = 0; i < k[2]; i++)
        if (p[2][i].coe != 0)
            j++;
    printf("%d", j);
    i = k[2];
    while(i--)
        if (p[2][i].coe != 0)
            printf(" %d %.1lf", i, p[2][i].coe);
    printf("\n");
    return 0;
}

