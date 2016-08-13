#include <iostream>
using namespace std;
const int Max = 110;
int *m = new int[Max + 1];
int *n = new int[Max + 1];
bool IsREqual() {
    int i(0), j(m[Max] - 1);
    while (i < j)
        if (m[i++] != m[j--])
            return false;
    return true;
}
void AddRev() {
    int *tmp = m;
    m = n;
    n = tmp;
    int i, sum(0);
    for (i = 0; i < n[Max]; i++) {
        sum += n[i] + n[n[Max] - 1 - i];
        m[i] = sum % 10;
        sum /= 10;
    }
    m[Max] = n[Max];
    if (sum) {
        m[i] = sum;
        m[Max]++;
    }
}

int main(void) {
    long int N;
    int K, i;
    cin >> N >> K;
    for (i = 0; N; i++) {
        m[i] = N % 10;
        N /= 10;
    }
    m[Max] = i;
    for (i = 0; i < K; i++) {
        if (IsREqual())
            break;
        else
            AddRev();
    }
    for (int j = m[Max] - 1; j >= 0; j--)
        cout << m[j];
    cout << endl;
    cout << i << endl;
    return 0;
}

