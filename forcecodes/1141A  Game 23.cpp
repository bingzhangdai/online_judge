#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int m, n, step(0);
    cin >> n >> m;
    int rem = m / n;
    const vector<int> num {2, 3};

    if (rem * n != m) {
        cout << -1 << endl;
        return 0;
    }

    for (auto i : num) {
        for (auto tmp = rem / i; tmp * i == rem; tmp = rem / i) {
            rem /= i;
            step++;
        }
    }

    if (rem != 1) {
        cout << -1 << endl;
    }
    else {
        cout << step << endl;
    }

    return 0;
}