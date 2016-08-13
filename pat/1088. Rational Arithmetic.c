#include <stdio.h>
long int abs(long int m) {
    if (m < 0)
        return -m;
    else
        return m;
}

long int gcd(long int m, long int n) {
    long int tmp;
    while (m % n != 0) {
        tmp = m % n;
        m = n;
        n = tmp;
    }
    return n;
}

void printm(long int k, long int a, long int b) {
    if (k < 0) {
        if (a == 0)
            printf("(%ld)", k);
        else
            printf("(%ld %ld/%ld)", k, a, b);
    } else if (k == 0) {
        if (a < 0) 
            printf("(%ld/%ld)", a, b);
        else if (a == 0)
            printf("0");
        else
            printf("%ld/%ld", a, b);
    } else {
        if (a == 0)
            printf("%ld", k);
        else
            printf("%ld %ld/%ld", k, a, b);
    }
}

void getright(long int *k, long int *a, long int *b) {
    long int flag = 1, g;
    if (*a < 0)
        flag = -1;
    *a = abs(*a);
    *k = flag * (*a) / *b;
    *a = *a % *b;
    g = gcd(*a, *b);
    *a = *a / g;
    *b = *b / g;
    if (*k == 0)
        *a = *a * flag;
}
void sum(long int a1, long int b1, long int a2, long int b2) {
    long int tmpk, tmpa, tmpb;
    tmpb = b1 * b2;
    tmpa = a1 * b2 + a2 * b1;
    getright(&tmpk, &a1, &b1);
    printm(tmpk, a1, b1);
    printf(" + ");
    getright(&tmpk, &a2, &b2);
    printm(tmpk, a2, b2);
    printf(" = ");
    getright(&tmpk, &tmpa, &tmpb);
    printm(tmpk, tmpa, tmpb);
    printf("\n");
}
void dif(long int a1, long int b1, long int a2, long int b2) {
    long int tmpk, tmpa, tmpb;
    tmpb = b1 * b2;
    tmpa = a1 * b2 - a2 * b1;
    getright(&tmpk, &a1, &b1);
    printm(tmpk, a1, b1);
    printf(" - ");
    getright(&tmpk, &a2, &b2);
    printm(tmpk, a2, b2);
    printf(" = ");
    getright(&tmpk, &tmpa, &tmpb);
    printm(tmpk, tmpa, tmpb);
    printf("\n");
}
void pro(long int a1, long int b1, long int a2, long int b2) {
    long int tmpk, tmpa, tmpb;
    tmpb = b1 * b2;
    tmpa = a1 * a2;
    getright(&tmpk, &a1, &b1);
    printm(tmpk, a1, b1);
    printf(" * ");
    getright(&tmpk, &a2, &b2);
    printm(tmpk, a2, b2);
    printf(" = ");
    getright(&tmpk, &tmpa, &tmpb);
    printm(tmpk, tmpa, tmpb);
    printf("\n");
}
void quo(long int a1, long int b1, long int a2, long int b2) {
    long int tmpk, tmpa, tmpb, flag = 1;
    if (a2 == 0) {
        getright(&tmpk, &a1, &b1);
        printm(tmpk, a1, b1);
        printf(" / ");
        getright(&tmpk, &a2, &b2);
        printm(tmpk, a2, b2);
        printf(" = ");
        printf("Inf\n");
        return;
    }
    tmpb = b1 * a2;
    tmpa = a1 * b2;
    if (tmpb < 0)
        flag = -flag;
    if (tmpa < 0)
        flag = -flag;
    tmpa = flag * abs(tmpa);
    tmpb = abs(tmpb);
    getright(&tmpk, &a1, &b1);
    printm(tmpk, a1, b1);
    printf(" / ");
    getright(&tmpk, &a2, &b2);
    printm(tmpk, a2, b2);
    printf(" = ");
    getright(&tmpk, &tmpa, &tmpb);
    printm(tmpk, tmpa, tmpb);
    printf("\n");
}
int main(void) {
    long int a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    sum(a1, b1, a2, b2);
    dif(a1, b1, a2, b2);
    pro(a1, b1, a2, b2);
    quo(a1, b1, a2, b2);
    return 0;
}

