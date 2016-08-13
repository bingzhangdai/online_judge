#include <iostream>
#include <limits.h>
using namespace std;
const int NotConnect = -1;
int Cmax, N, Sp, M, roads[500][500], curbike[500], visited[500];
int nextcity[500], path[500], totalback, totaltime(INT_MAX), totalsent(INT_MAX);
void init() {
    for (int i = 0; i <= N; i++)
        for  (int j = 0; j <= N; j++)
            roads[i][j] = NotConnect;
}

void savepath(){
    for (int i = 0; i <= N; i++)
        path[i] = nextcity[i];
}

void dfs(int city, int time, int bike, int sent, int takeback) {
    int num;
    visited[city] = 1;
    if (time > totaltime)
        return;
    if (takeback < 0)
        takeback = 0;
    if (bike < 0 && bike < sent)
        sent = bike;
    if (city == Sp) {
        if (time == totaltime) {
            if (totalsent > -sent) {
                totalsent = -sent;
                totalback = takeback;
                savepath();
            }
            if (totalsent == -sent) {
                if (totalback > takeback) {
                    totalback = takeback;
                    savepath();
                }
            }
        }
        else if (time < totaltime) {
            totaltime = time;
            totalback = takeback;
            totalsent = -sent;
            savepath();
        }
        return;
    }
    for (int i = 0; i <= N; i++)
        if (roads[city][i] != NotConnect && !visited[i]) {
            nextcity[city] = i;
            num = curbike[i] - Cmax/2;
            dfs(i, time + roads[city][i], bike + num, sent, takeback + num);
            visited[i] = 0;
        }
    return;
}

int main(void) {
    int i, j, k;
    cin >> Cmax >> N >> Sp >> M;
    for (i = 1; i <= N; i++)
        cin >> curbike[i];
    init();
    for (i = 0; i < M; i++) {
        cin >> j >> k;
        cin >> roads[j][k];
        roads[k][j] = roads[j][k];
    }
    dfs(0, 0, 0, 0, 0);
    cout << totalsent << " " << "0";
    for (i = path[0]; ; i = path[i]) {
        cout << "->" << i;
        if (i == Sp)
            break;
    }
    cout << " " << totalback << endl;
    return 0;
}

