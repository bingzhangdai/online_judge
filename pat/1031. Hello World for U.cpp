#include <iostream>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int N = s.size();
    int n1 = (N + 2) / 3;
    int n2 = N + 2 - 2*n1;
    for (int i = 0; i < n1 - 1; i++) {
        cout << s[i];
        for (int j = 0; j < n2 - 2; j++)
            cout << " ";
        cout << s[N-1-i] << endl;
    }
    for (int k = 0; k < n2; k++)
        cout << s[k+n1-1];
    cout << endl;
    return 0;
}

