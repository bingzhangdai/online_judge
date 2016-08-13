#include <iostream>
#include <limits.h>
using namespace std;

const int notvisited = 0;
const int visited = 1;
const int Max = 500;
const int Inf = INT_MAX;
int cnt;
int teams[Max];
int N;
int shortestdis = Inf;
int amount;
int visit[Max];
int map[Max][Max];
void initialize() {
    int i, j;
    for (i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            map[i][j] = Inf;
}

void dfs(int cur, int end, int dis, int accuteams) {
    if (cur == end) {
        if (shortestdis == dis) {
            cnt++;
            if (amount < accuteams)
                amount = accuteams;
        }
        else if (shortestdis > dis) {
            cnt = 1;
            amount = accuteams;
            shortestdis = dis;
        }
        return;
    }
    if (dis >= shortestdis)
        return;
    int i;
    for (i = 0; i < N; i++)
        if (map[cur][i] != Inf && visit[i] != visited) {
            visit[i] = visited;
            dfs(i, end, dis + map[cur][i], accuteams + teams[i]);
            visit[i] = notvisited;
        }
    return;
}

int main(void) {
    int M, c1, c2;
    int i, j, k;
    int maxteam;
    cin >> N >> M >> c1 >> c2;
    for (i = 0; i < N; i++)
        cin >> teams[i];
    initialize();
    for (i = 0; i < M; i++) {
        cin >> j >> k;
        cin >> map[j][k];
        map[k][j] = map[j][k];
    }
    visit[c1] = visited;
    dfs(c1, c2, 0, teams[c1]);
    cout << cnt << " " << amount << endl;
    return 0;
}

