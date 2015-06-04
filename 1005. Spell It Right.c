#include <stdio.h>

void PrintResult(int n);
void PrintNum(int n);

int main(void) {
    char N[100];
    int i, j, sum;
    scanf("%s", N);
    i = 0;
    sum = 0;
    while (N[i])
        sum += N[i++] - '0';
    PrintResult(sum);
    return 0;
}

void PrintResult(int n) {
    if (n < 10) {
        PrintNum(n);
        return;
    }
    PrintResult(n/10);
    printf(" ");
    PrintNum(n%10);
}

void PrintNum(int n){
    switch(n){
        case 0:
            printf("zero");
            break;
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        default:
            break;
    }
}



