#include <iostream>
#include <string>
using namespace std;

string *stu;
int hrank[4];
int (*grade)[4];
int N, M;

void rankf(int st, int j) {
    hrank[j] = 1;
    int i;
    for (i = 0; i < N; i++)
        if (grade[i][j] > grade[st][j])
            hrank[j]++;
}
void printrank() {
    int tmp = 0;
    for ( int i = 0; i < 4; i++)
        if (hrank[tmp] > hrank[i])
            tmp = i;
    cout << hrank[tmp];
    switch (tmp) {
        case 0:
            cout << " A" << endl; break;
        case 1:
            cout << " C" << endl; break;
        case 2:
            cout << " M" << endl; break;
        case 3:
            cout << " E" << endl; break;
        default:
            break;
    }
}

int main(void) {
    cin >> N >> M;
    stu = new string[N];
    grade = new int[N][4];
    int i, j;
    int st;
    for (i = 0; i < N; i++) {
        cin >> stu[i] >> grade[i][1] >> grade[i][2] >> grade[i][3];
        grade[i][0] = (grade[i][1]+grade[i][2]+grade[i][3])/3;
    }
    for (i = 0; i < M; i++) {
        string s;
        cin >> s;
        int flag = 0;
        for (j = 0; j < N; j++)
            if (stu[j] == s) {
                flag = 1;
                st = j;
                break;
            }
        if (flag == 0) {
            cout << "N/A" << endl;
            continue;
        }
        for (j = 0; j < 4; j++)
            rankf(st, j);
        printrank();
    }
    return 0;
}

