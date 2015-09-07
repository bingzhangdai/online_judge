#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int struc[101][3];
int N;
vector<int> seq;
int getchild(int rootn) {
    if (rootn == -1)
        return 0;
    return 1 + getchild(struc[rootn][0]) + getchild(struc[rootn][1]);
}
void bdtree(int rootn, int begin, int end) {
    int n = getchild(struc[rootn][0]);
    struc[rootn][2] = seq[begin + n];
    if (n > 0)
        bdtree(struc[rootn][0], begin, begin + n);
    if (begin + n + 1 < end)
        bdtree(struc[rootn][1], begin + n + 1, end);
}

void bfs() {
    deque<int> que;
    int root(0);
    cout << struc[root][2];
    if (struc[root][0] != -1)
        que.push_back(struc[root][0]);
    if (struc[root][1] != -1)
        que.push_back(struc[root][1]);
    while (que.size() != 0) {
        root = que[0];
        que.pop_front();
        if (struc[root][0] != -1)
            que.push_back(struc[root][0]);
        if (struc[root][1] != -1)
            que.push_back(struc[root][1]);
        cout << " " << struc[root][2];
    }
    cout << endl;

}


int main(void) {
    int n;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> struc[i][0] >> struc[i][1];
    for (int i = 0; i < N; i++) {
        cin >> n;
        seq.push_back(n);
    }
    sort(seq.begin(), seq.end());
    bdtree(0, 0, seq.size());
    bfs();
    return 0;
}

