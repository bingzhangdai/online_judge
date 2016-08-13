#include <iostream>
using namespace std;
const int size = 101;
const int ISort = 1;
const int HSort = 0;
int N, ini[size], targ[size];
int max() {
    int tmp(0);
    for (int i = 1; i < N; i++)
        if (ini[tmp] < ini[i])
            tmp = i;
    return ini[tmp];
}

int judge() {
    int m = max();
    if (targ[N-1] < m)
        return ISort;
    else if (targ[0] < targ[1])
        return ISort;
    else
        return HSort;
}
void InSort() {
    int i, j, tmp;
    for (i = 0; i < N-1; i++)
        if (targ[i] > targ[i+1])
            break;
    tmp = targ[i+1];
    while (targ[i] > tmp && i>= 0) {
        targ[i+1] = targ[i];
        i--;
    }
    targ[i+1] = tmp;
}
void HeapSort() {
    int i, j, tmp, l, r;
    for (i = N-1; i >= 0; i--)
        if (targ[i] < targ[0])
            break;
    tmp = targ[i];
    targ[i] = targ[0];
    targ[0] = tmp;
    for (j = 0 ; 2*j+1 < i;) {
        l = 2*j+1;
        r = l + 1;
        if (targ[l] < tmp)
            break;
        if (r < i && targ[r] > targ[l]) {
            targ[j] = targ[r];
            j = r;
        } else {
            targ[j] = targ[l];
            j = l;
        }
    }
    targ[j] = tmp;

}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> ini[i];
    for (int i = 0; i < N; i++)
        cin >> targ[i];
    if (judge() == ISort) {
        cout << "Insertion Sort" << endl;
        InSort();
    }
    else {
        cout << "Heap Sort" << endl;
        HeapSort();
    }
    cout << targ[0];
    for (int i = 1; i < N; i++)
        cout << " " << targ[i];
    cout << endl;
    return 0;
}
