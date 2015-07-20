#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int *A = new int[N];
    int i, j, left, right;
    for (i = 0; i < N; i++)
        cin >> A[i];
    int thissum, maxsum = -1;
    for (i = 0; i < N; i++) {
        thissum = 0;
        for (j = i; j < N; j++) {
            thissum += A[j];
            if (thissum > maxsum){
                maxsum = thissum;
                left = i;
                right = j;
            }
        }
    }
    if (maxsum < 0){
        cout << "0 " << A[0] << " " << A[N-1] << endl;
        delete[] A;
        return 0;
    }
    cout << maxsum << " " << A[left] << " " << A[right] << endl;
    delete[] A;
    return 0;
}

