#include <stdio.h>

int main(void) {
    int i, cur, next, time, n;
    scanf("%d", &n);
    cur = 0; time = 0;
    for (i = 0; i < n; i++){
        scanf("%d", &next);
        if (next > cur)
            time += 6 * (next - cur);
        else
            time += 4 * (cur - next);
        cur = next;
    }
    time += 5 * n;
    printf("%d", time);
    return 0;
}
