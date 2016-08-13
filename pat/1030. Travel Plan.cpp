#include <iostream>
#include <limits.h>
using namespace std;
int mdistance[501][501], cost[501][501], visited[501], path[501], fpath[501];
int N, S, D, tdist(INT_MAX), tcost(INT_MAX);
void savepath() {
    for(int j = 0; j < N; j++)
        fpath[j] = path[j];
}
void dfs(int city, int dist, int cst) {
    if (city == D) {
        if (dist < tdist) {
            tdist = dist;
            tcost = cst;
            savepath();
        }
        else if (dist == tdist) {
            if (cst < tcost) {
                tcost = cst;
                savepath();
            }
        }
        return;
    }
    if (dist > tdist)
        return;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && mdistance[city][i] != 0) {
            visited[i] = 1;
            path[city] = i;
            dfs (i, dist+mdistance[city][i], cst+cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main(void) {
    int c1, c2, M;
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++) {
        cin >> c1 >> c2;
        cin >> mdistance[c1][c2] >> cost[c1][c2];
        mdistance[c2][c1] = mdistance[c1][c2];
        cost[c2][c1] = cost[c1][c2];
    }
    visited[S] = 1;
    dfs(S, 0, 0);
    for (int i = S; i != D; i = fpath[i])
        cout << i << " ";
    cout << D << " " << tdist << " " << tcost << endl;
    return 0;
}

