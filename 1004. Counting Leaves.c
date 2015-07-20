#include <stdio.h>

#define max 100

int hierarchy[max][max];
int leaves[max];
int maxlevel;
int N, M;

void dfs(int cur, int level) {
    int flag = 0;
    int i;
    for (i = 1; i <= N; i++)
        if (hierarchy[cur][i] != 0) {
            flag = 1;
            dfs(i, level + 1);
        }
    if (flag == 0)
        leaves[level]++;
    if (maxlevel < level)
        maxlevel = level;
    return;
}

int main(void) {
    int i, j, k, ID, m;
    scanf("%d%d", &N, &M);
    for (i = 0; i < M; i++) {
        scanf("%d%d", &ID, &m);
        for (j = 0; j < m; j++) {
            scanf("%d", &k);
            hierarchy[ID][k] = 1;
        }
    }
    dfs(1, 0);
    for (i = 0; i < maxlevel; i++)
        printf("%d ", leaves[i]);
    printf("%d\n", leaves[i]);
    return 0;
}

