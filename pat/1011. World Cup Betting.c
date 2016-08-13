#include <stdio.h>

float info[3][3];
void printbet(int tmp) {
    switch (tmp){
        case 0:
            printf("W ");
            break;
        case 1:
            printf("T ");
            break;
        case 2:
            printf("L ");
            break;
        default:
            break;
    }
}
int main(void) {
    int i, j;
    int tmp;
    float profit = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%f", &info[i][j]);
    for (i = 0; i < 3; i++) {
        tmp = 0;
        for (j = 0; j < 3; j++) {
            if (info[i][j] > info[i][tmp])
                tmp = j;
        }
        printbet(tmp);
        profit *= info[i][tmp];
    }
    printf("%.2f\n", (profit*0.65-1)*2);
    return 0;
}

