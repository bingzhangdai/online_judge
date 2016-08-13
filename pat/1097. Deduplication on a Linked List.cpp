#include <stdio.h>
#include <limits.h>
#include <map>
using namespace std;
const int visited = 1;
const int notvist = 0;
map<int, int> list;
map<int, int> keys;
map<int, int> removed;
map<int, int> flags;

int main(void) {
    int first, N, add1, add2, key, flag(0), remfir, rem1;
    scanf("%d%d", &first, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &add1, &key, &add2);
        list[add1] = add2;
        keys[add1] = key;
        flags[key] = flags[-key] = notvist;
    }
    printf("%05d %d ", first, keys[first]);
    flags[ keys[first] ] = flags[ -keys[first] ] = visited;
    for (first = list[first]; first != -1; first = list[first]) {
        if (flags[ keys[first] ] == notvist) {
            printf("%05d\n%05d %d ", first, first, keys[first]);
            flags[ keys[first] ] = flags[ -keys[first] ] = visited;
        }
        else {
            if (flag == 0) {
                remfir = rem1 = first;
                flag = 1;
            }
            else {
                list[rem1] = first;
                rem1 = first;
            }
        }
    }
    list[rem1] = -1;
    printf("-1\n");
    if (flag == 0)
        return 0;
    printf("%05d %d ", remfir, keys[remfir]);
    for (remfir = list[remfir]; remfir != -1; remfir = list[remfir] ) {
        printf("%05d\n%05d %d ", remfir, remfir, keys[remfir]);
    }
    printf("-1\n");

    
    return 0;
}

