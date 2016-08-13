#include <stdio.h>
#include <stdlib.h>
char orig[80];
char type[80];
char worn[80];

void Insert(char c) {
    int i;
    if (c <= 'z' && c >= 'a')
        c = c - 'a' + 'A';
    for (i = 0; worn[i] != '\0'; i++)
        if (worn[i] == c)
            break;
    if (!worn[i])
        worn[i] = c;
}

int main(void) {
    int i, j;
    scanf("%s%s", orig, type);
    for (i = j = 0; orig[i] != '\0'; i++)
        if (orig[i] == type[j])
            j++;
        else
            Insert(orig[i]);
    for (i = 0; worn[i] != '\0'; i++)
        printf("%c", worn[i]);
    printf("\n");
    return 0;
}

