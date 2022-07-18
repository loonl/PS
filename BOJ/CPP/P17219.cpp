#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    int n, m; cin >> n >> m;
    string id, pw;
    map<string, string> db;
    for (int i = 0; i < n; i++) {
        cin >> id >> pw;
        db[id] = pw;
    }

    string site;
    for (int i = 0; i < m; i++) {
        cin >> site;
        auto find = db.find(site);
        cout << find->second << "\n";
    }

    return 0;
}