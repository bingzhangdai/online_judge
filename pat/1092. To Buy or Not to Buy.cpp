#include <stdio.h>
#include <map>
using namespace std;
char shop[1001], eva[1001];
map<char, int> buy;

int main(void) {
    int flag = true, i, j, miss(0);
    scanf("%s%s", shop, eva);
    for (i = 0; shop[i] != '\0'; i++)
        buy[ shop[i] ] ++;
    for (j = 0; eva[j] != '\0'; j++) {
        if (--buy[ eva[j] ] < 0)
            flag = false;
    }
    if (flag) {
        printf("Yes %d\n", i - j);
    } else {
        for (auto elem : buy)
            if (elem.second < 0)
                miss += elem.second;
        printf("No %d\n", -miss);
    }
    return 0;
}

