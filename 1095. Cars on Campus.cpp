#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
class Car {
public:
    string ID;
    string status;
    int time;
};
vector<Car> records;
map<string, int> campus;
map<string, int>::iterator it;
map<string, int> TTime;

bool TSort(const Car& c1, const Car& c2) {
    return c1.time < c2.time;
}
bool IdSort(const Car& c1, const Car& c2) {
    if (c1.ID != c2.ID)
        return c1.ID < c2.ID;
    else
        return TSort(c1, c2);
}
void deldup() {
    int flag = 0;
    sort(records.begin(), records.end(), IdSort);
    for (int i = 0; i < records.size(); i++) {
        if (flag == 0) {
            if (records[i].status == "out")
                records[i].time = -1;
            else
                flag = 1;
        } else {
            if (records[i].status == "in" && records[i].ID == records[i-1].ID) {
                records[i-1].time = -1;
            } else if (records[i].status == "out" && records[i].ID != records[i-1].ID) {
                records[i-1].time = records[i].time = -1;
                flag = 0;
            } else if (records[i].status == "in" && records[i].ID != records[i-1].ID)
                records[i-1].time = -1;
            else
                flag = 0;
        }
    }
    if (flag)   records[records.size()-1].time = -1;
}


int main(void) {
    int N, K, hh, mm, ss, tmp, time(0);
    char ign;
    Car car;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> car.ID >> hh >> ign >> mm >> ign >> ss >> car.status;
        time = hh*3600 + mm*60 + ss;
        car.time = time;
        records.push_back(car);
    }
    deldup();
    sort(records.begin(), records.end(), TSort);
    cin >> hh >> ign >> mm >> ign >> ss;
    time = hh*3600 + mm*60 + ss;
    for (int i = 0; i < records.size(); i++) {
        if (records[i].time == -1)
            continue;
        while (K && time < records[i].time) {
            cout << campus.size() << endl;
            cin >> hh >> ign >> mm >> ign >> ss;
            time = hh*3600 + mm*60 + ss;
            K--;
        }
        if (records[i].status == "in")
            campus[ records[i].ID ] = records[i].time;
        else {
            it = campus.find( records[i].ID );
            TTime [ records[i].ID ] += records[i].time - (*it).second;
            campus.erase(it);
        }
    }
    while (K--) {
        // cin >> hh >> ign >> mm >> ign >> ss;
        cout << campus.size() << endl;
    }
    for (auto elem = it = TTime.begin(); elem != TTime.end(); ++elem) {
        if ((*elem).second > (*it).second)
            it = elem;
    }
    for (auto elem = TTime.begin(); elem != TTime.end(); ++elem) {
        if ((*elem).second == (*it).second)
            cout << (*elem).first << " ";
    }
    time = (*it).second;
    hh = time / 3600;
    mm = (time % 3600) / 60;
    ss = time % 60;
    cout << setw(2) << setfill('0') << hh << ":"
        << setw(2) << setfill('0') << mm << ":"
        << setw(2) << setfill('0') << ss << endl;
    return 0;
}

