#include <iostream>
using namespace std;

class person {
    string ID;
    double signin;
    double signout;
public:
    person(string s, double in, double out) 
        : ID(s), signin(in), signout(out) {}
    void printID (void) { cout << ID; }
    friend void searchin(int n);
    friend void searchout(int n);
};

void searchin(int n);
void searchout(int n);

person *a[1000];

int main(void) {
    int i, n; cin >> n;
    char c;
    double in, out, tmp;
    string s;
    for (i = 0; i < n; i++) {
        cin >> s;
        cin >> tmp; in = 60*tmp;
        cin >> c >> tmp; in += tmp;
        cin >> c >> tmp; in += tmp/60;
        cin >> tmp; out = 60*tmp;
        cin >> c >> tmp; out += tmp;
        cin >> c >> tmp; out += tmp/60;
        a[i] = new person(s, in, out);
    }
    searchin(n);
    a[0]->printID(); cout << " "; 
    searchout(n);
    a[n-1]->printID(); cout << endl;
    return 0;
}

void searchin(int n){
    int i, j;
    person *tmp;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            if (a[j]->signin < a[i]->signin){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
}
void searchout(int n){
    int i, j;
    person *tmp;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            if (a[j]->signout < a[i]->signout){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
}
