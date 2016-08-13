#include <stdio.h>
#include <map>
using namespace std;
const int End = 61200;
const int Begin = 28800;
map<int, int> arrline;
int win[100];
void init(int K) {
    for (int i = 0; i < K; i++)
        win[i] = Begin;
}
int findsmall(int K) {
    int tmp = 0;
    for (int i = 0; i < K; i++)
        if (win[i] < win[tmp])
            tmp = i;
    return tmp;
}
int main(void) {
    int i, N, K, HH, MM, SS, pro, t1, t2, count(0);
    float waitime(0);
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%d:%d:%d %d", &HH, &MM, &SS, &pro);
        t1 = HH*3600 + MM*60 +SS;
        t2 = pro * 60;
        if (t1 <= End) {
            count ++;
                if (t2 > 3600)
                    arrline.insert({t1, 3600});
                else
                    arrline.insert({t1, t2});
        }
    }
    init(K);
    for (const auto& p : arrline) {
        i = findsmall(K);
        if (win[i] <= p.first)
            win[i] = p.first + p.second;
        else {
            waitime += win[i] - p.first;
            win[i] += p.second;
        }
    }
    printf("%.1f\n", waitime/60/count);
    return 0;
}
