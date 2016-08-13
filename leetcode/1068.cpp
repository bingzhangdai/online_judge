#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
int pays[101], path[10000][101];

int main(void) {
    int N, M;
    vector<int> coins = vector<int>();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        coins.push_back(v);
    }
    sort(coins.begin(), coins.end(), [](int m, int n){ return m > n; });

    pays[0] = 0;
    for (int i = 1; i <= M; i++)
        pays[i] = INT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = M; j >= coins[i]; j--)
            if (pays[j] > pays[j - coins[i]] + coins[i]) {
                path[i][j] = j;
                pays[j] = pays[j];
            }
            else {
                path[i][j] = j - coins[i];
                pays[j] = (pays[j - coins[i]] + coins[i]) >= 0 ? pays[j- coins[i]] + coins[i] : INT_MIN;
            }
    }

    vector<int> res = vector<int>();
    if (pays[M] < 0)
        cout << "No Solution" << endl;
    else {
        int j = M;
        for (int i = N-1; i >= 0; i--) {
            if (j != path[i][j])
                res.push_back(coins[i]);
            j = path[i][j];
        }
        cout << res[0];
        for (int i = 1; i < res.size(); i++)
            cout << " " << res[i];
        cout << endl;
    }
    return 0;
}
