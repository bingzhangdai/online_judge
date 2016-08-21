#include <iostream>
#include <map>
#include <vector>
using namespace std;
int length[10001];
map<int, int> order = map<int, int>();
vector<int> stripe = vector<int>();

int main(void) {
    int L, N, M, c, s;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> c;
        order[c] = i;
    }
    cin >> L;
    while (L--) {
        cin >> s;
        if (order.count(s) == 1)
            stripe.push_back(order[s]);
    }
    if (stripe.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < stripe.size(); i++) {
        length[i] = 1;
    }
    for (int i = 1; i < stripe.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (stripe[j] <= stripe[i]) {
                length[i] = max(length[j] + 1, length[i]);
            }
        }
    }
    int m = 0;
    for (int i = 0; i < stripe.size(); i++)
        m = max(m, length[i]);
    cout << m << endl;
    return 0;
}

