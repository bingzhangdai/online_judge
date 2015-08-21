#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int i, flag(0), num, count[10], carry(0);
    string s1, s2;
    cin >> s1;
    for (i = 0; i < 10; i++)
        count[i] = 0;
    for (i = s1.size() - 1; i >= 0; i--) {
        num = s1[i] - '0';
        count[num]++;
        num = num << 1;
        num += carry;
        s2 += num % 10 + '0';
        carry = num / 10;
        count[num % 10]--;
    }
    if (carry)
        s2 += carry + '0';
    for (i = 0; i < 10; i++)
        if (count[i] != 0) {
            flag = 1;
            break;
        }
    if (flag)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    for (i = s2.size() - 1; i >= 0; i--)
        cout << s2[i];
    cout << endl;
    return 0;
}

