#include <stdio.h>
#include <stdlib.h>
int N, M, levels[100], tree[100][100], visited[100];

void dfs(int root, int level) {
    int i;
    visited[root] = 1;
    levels[level]++;
    for (i = 1; i <= N; i++)
            if (!visited[i] && tree[root][i])
                dfs(i, level + 1);
}
int findmax(int *curlevel) {
    int i;
    for (i = *curlevel = 1; levels[i]; i++)
        if (levels[i] > levels[*curlevel])
            *curlevel = i;
    return levels[*curlevel];
}

int main(void) {
    int i, j, K, p, c, maxp, maxl;
    scanf("%d%d", &N, &M);
    for (i = 0; i < M; i++) {
        scanf("%d%d", &p, &K);
        for (j = 0; j < K; j++) {
            scanf("%d", &c);
            tree[p][c] = 1;
        }
    }
    dfs(1, 1);
    maxp = findmax(&maxl);
    printf("%d %d\n", maxp, maxl);
    return 0;
}

