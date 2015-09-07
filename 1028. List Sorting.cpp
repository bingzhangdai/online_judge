#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
string info[3];
char tmp[10];

int main(void) {
    int N, C, i;
    map<string, map<string, string>> records;
    scanf("%d%d", &N, &C);
    for (i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%s", tmp);
            info[j] = tmp;
        }
        records[info[C-1]][info[0]] = info[0]+" "+info[1]+" "+info[2];
    }
    for (auto& elem : records)
        for (auto& it : elem.second)
            printf("%s\n", it.second.c_str());
    return 0;
}

