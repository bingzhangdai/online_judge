#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;
int rate[24];
class Records {
public:
    int month;
    int day;
    int hour;
    int minute;
    string status;
};
map<string, map<int, Records> > per; // elegant, lol

void printprice(int total) {
    cout << "$" << total/100 << "." << setw(2) << setfill('0') << total%100 << endl;
}

int charge(int time) {
    int sum(0), h(time/60), m(time%60), i;
    for (i = 0; i < h; i++)
        sum += rate[i%24] * 60;
    return sum + m * rate[i%24];
}
    
int getprice(map<int, Records>::iterator st1, map<int, Records>::iterator st2) {
    Records& r1((*st1).second), r2((*st2).second);
    int sum = charge((*st2).first) - charge((*st1).first);
    cout << setw(2) << setfill('0') << r1.day << ":" << setw(2) << setfill('0') 
        << r1.hour << ":" << setw(2) << setfill('0') << r1.minute
        << " " << setw(2) << setfill('0') << r2.day << ":" << setw(2) << setfill('0') 
        << r2.hour << ":" << setw(2) << setfill('0') << r2.minute
        << " " << (*st2).first - (*st1).first << " ";
    printprice(sum);
    return sum;
}

int main(void) {
    string name;
    Records rcd;
    int time, total;
    int i, flag, N;
    char ign;
    map<int, Records>::iterator st1, st2;
    for (i = 0; i < 24; i++)
        cin >> rate[i];
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> name >> rcd.month >> ign >> rcd.day >> ign >> rcd.hour >> ign >> rcd.minute >> rcd.status;
        int time = rcd.day*24*60 + rcd.hour*60 + rcd.minute;
        per[name].insert({time, rcd});
    }
    for (auto& p : per) {
        flag = 0;
        total = 0;
        for (st1 = p.second.begin(); st1 != p.second.end(); ++st1) {
            if ((*st1).second.status == "on-line") {
                st2 = st1;
                flag = 1;
            }
            if ((*st1).second.status == "off-line" && flag == 1) {
                if (total == 0) {
                    cout << p.first << " " << setw(2) << setfill('0') << (*st1).second.month << endl;
                }
                total += getprice(st2, st1);
                flag = 0;
            }
        }
        if (total != 0) {
            cout << "Total amount: ";
            printprice(total);
        }
    }
    return 0;
}

