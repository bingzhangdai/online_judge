#include <iostream>
using namespace std;

int N, M, K;
int map[1000][1000]; // starts with 1
int visited[1000]; // starts with 1
int check[1000]; // starts with 0
int count;
int cut;

void initial(){
    int i;
    for (i = 1; i <= N; i++)
        visited[i] = 0;
    count = -1;
}

void dfs(int city) {
    visited[city] = 1;
    int i;
    for (i = 1; i <= N; i++) {
        if (map[city][i] != 0 && !visited[i]) {
            dfs(i);
        }
    }
}

int main(void) {
    int i, j;
    int c1, c2;
    cin >> N >> M >> K;
    for (i = 0; i < M; i++){
        cin >> c1 >> c2;
        map[c1][c2] = map[c2][c1] = 1;
    }
    for (i = 0; i < K; i++)
        cin >> check[i];
    for (i = 0; i < K; i++){
        initial();
        cut = check[i];
        visited[cut] = 1;
        for (j = 1; j <= N; j++)
            if (!visited[j]) {
                dfs(j);
                count ++;
            }
        cout << count << endl;
    }
    return 0;
}

