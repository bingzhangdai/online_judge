#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;
const int finished = -1;
int N, M, K;
int win[20][1001]; // waiting queue, marvelous, i must be talent
int wintime[20];
int fintime[1000]; // 1
int protime[1000]; // begin with 1
void printt(int cstm) {
    cout << setw(2) << setfill('0') << fintime[cstm]/60+8;
    cout << ":" << setw(2) << setfill('0') << fintime[cstm]%60 << endl;
}
int findshort() {
    int i, tmp = 1;
    for (i = 1; i <= N; i++)
        if (wintime[i%N] < wintime[tmp%N])
            tmp = i;
    if (wintime[tmp%N] == INT_MAX)
        return -1;
    return tmp%N;
}

int main(void) {
    int Q, cstm;
    int i, j;
    int tmp, cur;
    cin >> N >> M >> K >> Q;
    for (i = 1; i <= K; i++)
        cin >> protime[i];
    if (K <= M*N) {
        for (i = 1; i <= K; i++)
            fintime[i] = wintime[i%N] += protime[i];
    }
    else {
        for (cur = 1; cur <= M*N; cur++)
            win[cur%N][cur/(N+1)+1] = cur;
        for (i = 1; i <= N; i++) {
            win[i%N][0] = 1;
            win[i%N][1000] = M;
            fintime[i] = wintime[i%N] = protime[i];
        }
        for (tmp = findshort(); tmp != finished; tmp = findshort()) {
            cstm = win[tmp][1000];
            if (cur <= K) {
                win[tmp][cstm+1] = cur;
                win[tmp][1000]++;
                cur++;
            }
            cstm = ++win[tmp][0];
            if (win[tmp][cstm] == 0) {
                wintime[tmp] = INT_MAX;
                continue;
            }
            if (wintime[tmp] >= 540)
                fintime[ win[tmp][cstm] ] = -1;
            else
                fintime[ win[tmp][cstm] ] = wintime[tmp] += protime[ win[tmp][cstm] ];
        }
    }
    for (i = 0; i < Q; i++) {
        cin >> cstm;
        if (fintime[cstm] == -1)
            cout << "Sorry" << endl;
        else
            printt(cstm);
    }
    return 0;
}

