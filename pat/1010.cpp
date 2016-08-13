#include <iostream>
using namespace std;

string N[2];

long long int radixtoten(string s, int radix) {
    long long int n(0);
    long long int i;
    for (i = 0; i < s.size(); i++)
        if (s[i] >= 'a')
            n = n*radix + s[i] - 'a' + 10;
        else
            n = n*radix + s[i] - '0';
    return n;
}

int maxradix(string s) {
    int i, n = 0;
    for (i = 0; i < s.size(); i++)
        if (s[i] >= 'a')
            n = (n > s[i]-'a'+10) ? n : (s[i]-'a'+10);
        else
            n = (n > s[i]-'0') ? n : (s[i]-'0');
    return n;
}


int main(void) {
    long long int tag, radix;
    cin >> N[0] >> N[1] >> tag >> radix;
    long long int n1, n2;
    long long int flag = 0;
    long int max;
    long int tag1, tag2;
    if (tag == 1) {
        tag1 = 0;
        tag2 = 1;
    }
    else {
        tag1 = 1;
        tag2 = 0;
    }
    long long int i;
    max = maxradix(N[tag2]) + 1;
    n1 = radixtoten(N[tag1], radix);
    long long int mmax = (n1 > max) ? n1 : max;
    if (N[tag1].size() > N[tag2].size())
        SMALLER:
        for (i = ((radix > max) ? radix : max); i <= mmax; i++) {
            n2 = radixtoten(N[tag2], i);
            if (n1 == n2) {
                flag = i;
                break;
            }
            else if (n1 < n2) {
                break;
            }
        }
    else if (N[tag1].size() < N[tag2].size()) {
        if (max < radix)
            LARGER:
            for (i = max; i < radix; i++) {
                n2 = radixtoten(N[tag2], i);
                if(n1 == n2) {
                    flag = i;
                    break;
                }
            }
    }
    else {
        if (N[tag1] > N[tag2])
            goto SMALLER;
        else if (N[tag1] < N[tag2])
            goto LARGER;
        else
            if (N[tag1] == string("1"))
                flag = 2;
            else
                flag = radix;
    }
    if (flag == 0)
        cout << "Impossible" << endl;
    else
        cout << flag << endl;
    return 0;
}

