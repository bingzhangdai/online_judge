#include <iostream>
#include <set>
using namespace std;
int N, edge[10001][10001], visited[10001], levels[10001];
set<int> roots;

void dfs(int n, int level) {
    visited[n] = 1;
    levels[n] = level;
    for (int i = 1; i <= N; i++)
        if (edge[n][i] && !visited[i])
            dfs(i, level + 1);
}
int savedeep() {    // return one of the deepest node/root;
    int n, i;
    for (n = i = 1; i <= N; i++)
        if (levels[i] > levels[n])
            n = i;
    for (i = 1; i <= N; i++)
        if (levels[i] == levels[n])
            roots.insert(i);
    return n;
}

int main(void) {
    int i, n1, n2, K(0);
    cin >> N;
    for (i = 0; i < N-1; i++) {
        cin >> n1 >> n2;
        edge[n1][n2] = edge[n2][n1] = 1;
    }
    for (i = 1; i <= N; i++)
        if (!visited[i]) {
            K++;
            dfs(i, 0);
        }
    if (K > 1) {
        cout << "Error: " << K << " components" << endl;
        return 0;
    }
    for (i = 1; i <= N; i++)
        visited[i] = 0;
    dfs(savedeep(), 0);
    savedeep();
    for (auto elem : roots)
        cout << elem << endl;

    return 0;
}

