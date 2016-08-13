#include <iostream>
#include <deque>
using namespace std;

deque<int> coll;
bool IsPld(int N, int b) {
    int sum(0), n(N);
    if (N == 0) {
        coll.push_front(0);
        return true;
    }
    while (N) {
        sum = sum * b + N % b;
        coll.push_front(N % b);
        N /= b;
    }
    return n == sum;
}

int main(void) {
    int i, N, b;
    cin >> N >> b;
    if (IsPld(N, b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (i = 0; i < coll.size()-1; i++)
        cout << coll[i] << " ";
    cout << coll[i] << endl;
    return 0;
}

