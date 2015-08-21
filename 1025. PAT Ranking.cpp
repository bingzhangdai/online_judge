#include <iostream>
#include <map>
#include <set>
using namespace std;

map<int, map<string, int>> total;
map<int, set<string>> local[100];
map<string, int> location;

int main(void) {
    int N, K, score, k, l, num(0);
    string id;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        num += K;
        for (int j = 0; j < K; j++) {
            cin >> id >> score;
            local[i][score].insert(id);
            total[score].insert({id, 0});
            location[id] = i+1;
        }
        int l = k = 1;
        for (auto elem = local[i].rbegin(); elem != local[i].rend(); ++elem) {
            for (auto& it : (*elem).second) {
                total[(*elem).first][it] = l;
                k++;
            }
            l = k;
        }
    }
    cout << num << endl;
    l = k = 1;
    for (auto elem = total.rbegin(); elem != total.rend(); ++ elem) {
        for (auto& it : (*elem).second) {
            cout << it.first << " " << l << " " << location[it.first] << " " << it.second << endl;
            k++;
        }
        l = k;
    }
    return 0;
}

