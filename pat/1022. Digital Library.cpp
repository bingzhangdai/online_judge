#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;

int main(void) {
    map<string, set<string> > books;
    map<string, set<string> >:: iterator elem;
    string ID, title, author, keywds, publisher, year, query;
    int N, M, i, j;
    cin >> N; getchar();
    while(N--) {
        getline(cin, ID);
        getline(cin, title); books["1: "+title].insert(ID);
        getline(cin, author); books["2: "+author].insert(ID);
        getline(cin, keywds);
        for (i = j = 0; j != string::npos; i = j + 1) {
            j = keywds.find(" ", i);
            books["3: "+keywds.substr(i, j-i)].insert(ID);
        }
        getline(cin, publisher); books["4: "+publisher].insert(ID);
        getline(cin, year); books["5: "+year].insert(ID);
    }
    cin >> M; getchar();
    while (M--) {
        getline(cin, query); cout << query << endl;
        elem = books.find(query);
        if (elem == books.end()) {
            cout << "Not Found" << endl;
        }
        else {
            for (const auto& it : (*elem).second)
                cout << it << endl;
        }
    }

    return 0;
}

